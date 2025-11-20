#include "BlackjackViewModel.h"
#include <QStringList>
#include "Strings.h"
#include "Constants.h"

BlackjackViewModel::BlackjackViewModel(QObject* parent)
    : QObject(parent)
{
    m_statusMessage = Strings::STATUS_START;
    m_model.resetAndShuffleDeck();
    emit viewDataChanged();
}

void BlackjackViewModel::deal() {
    if (m_model.chips < m_model.bet) {
        m_statusMessage = Strings::STATUS_OUT_OF_CHIPS;
        emit viewDataChanged();
        return;
    }
    if (m_model.deckPos > Constants::RESHUFFLE_THRESHOLD) {
        m_model.resetAndShuffleDeck();
    }
    m_model.player.clear();
    m_model.dealer.clear();
    m_model.roundActive = true;
    m_model.dealerHoleRevealed = false;

    m_model.player.push_back(m_model.draw());
    m_model.dealer.push_back(m_model.draw());
    m_model.player.push_back(m_model.draw());
    m_model.dealer.push_back(m_model.draw());

    if (BlackjackModel::handValue(m_model.player) == 21) {
        m_model.dealerHoleRevealed = true;
        auto dealerVal = m_model.dealerPlay();
        finishRound(BlackjackModel::determineOutcome(BlackjackModel::handValue(m_model.player), dealerVal));
    } else {
        m_statusMessage = Strings::STATUS_CHOOSE;
        emit viewDataChanged();
    }
}

void BlackjackViewModel::hit() {
    if (!m_model.roundActive) return;
    m_model.player.push_back(m_model.draw());
    int val = BlackjackModel::handValue(m_model.player);
    if (val > 21) {
        m_model.dealerHoleRevealed = true;
        finishRound(BlackjackModel::Outcome::DealerWin, Strings::MSG_BUST_DEALER_WINS);
    } else if (val == 21) {
        stand();
    } else {
        m_statusMessage = Strings::STATUS_DREW;
        emit viewDataChanged();
    }
}

void BlackjackViewModel::stand() {
    if (!m_model.roundActive) return;
    m_model.dealerHoleRevealed = true;
    int dealerVal = m_model.dealerPlay();
    int playerVal = BlackjackModel::handValue(m_model.player);
    finishRound(BlackjackModel::determineOutcome(playerVal, dealerVal));
}

QString BlackjackViewModel::dealerText() const {
    bool hide = !(m_model.dealerHoleRevealed);
    return handToText(m_model.dealer, hide);
}

QString BlackjackViewModel::dealerTotalText() const {
    bool hide = !(m_model.dealerHoleRevealed);
    if (hide && !m_model.dealer.empty()) {
        std::vector<int> tmp;
        if (m_model.dealer.size() >= 2) tmp.push_back(m_model.dealer[1]);
        return Strings::FMT_TOTAL_WITH_HIDDEN.arg(BlackjackModel::handValue(tmp));
    }
    return Strings::FMT_TOTAL.arg(BlackjackModel::handValue(m_model.dealer));
}

QString BlackjackViewModel::playerText() const { return handToText(m_model.player, false); }

QString BlackjackViewModel::playerTotalText() const { return Strings::FMT_TOTAL.arg(BlackjackModel::handValue(m_model.player)); }

QString BlackjackViewModel::chipsText() const { return Strings::FMT_CHIPS.arg(m_model.chips).arg(m_model.bet); }

QString BlackjackViewModel::statusText() const { return m_statusMessage; }

bool BlackjackViewModel::dealEnabled() const { return (m_model.chips >= m_model.bet) && !m_model.roundActive; }
bool BlackjackViewModel::hitEnabled() const { return m_model.roundActive; }
bool BlackjackViewModel::standEnabled() const { return m_model.roundActive; }

QString BlackjackViewModel::outcomeToMessage(BlackjackModel::Outcome o) {
    switch (o) {
        case BlackjackModel::Outcome::PlayerWin: return Strings::MSG_PLAYER_WIN;
        case BlackjackModel::Outcome::DealerWin: return Strings::MSG_DEALER_WIN;
        case BlackjackModel::Outcome::Push: return Strings::MSG_PUSH;
    }
    return "";
}

void BlackjackViewModel::finishRound(BlackjackModel::Outcome outcome, const QString& customMessage) {
    int delta = 0;
    if (outcome == BlackjackModel::Outcome::PlayerWin) delta = m_model.bet;
    else if (outcome == BlackjackModel::Outcome::DealerWin) delta = -m_model.bet;
    m_model.chips += delta;
    m_model.roundActive = false;
    QString baseMsg = customMessage.isEmpty() ? outcomeToMessage(outcome) : customMessage;
    m_statusMessage = baseMsg + Strings::STATUS_PLAY_AGAIN_SUFFIX;
    emit viewDataChanged();
}

QString BlackjackViewModel::handToText(const std::vector<int>& hand, bool hideFirst) {
    QStringList parts;
    for (size_t i = 0; i < hand.size(); ++i) {
        if (hideFirst && i == 0) { parts << Strings::HIDDEN_CARD; }
        else { parts << BlackjackModel::cardToString(hand[i]); }
    }
    return parts.join("  ");
}
