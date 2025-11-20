#include "BlackjackModel.h"
#include <QRandomGenerator>
#include <algorithm>
#include "Strings.h"
#include "Constants.h"

BlackjackModel::BlackjackModel(QObject* parent) : QObject(parent) {}

void BlackjackModel::resetAndShuffleDeck() {
    deck.resize(Constants::DECK_SIZE);
    for (int i = 0; i < Constants::DECK_SIZE; ++i) deck[i] = i;
    auto* rng = QRandomGenerator::global();
    std::shuffle(deck.begin(), deck.end(), *rng);
    deckPos = 0;
}

int BlackjackModel::draw() {
    if (deckPos >= static_cast<int>(deck.size())) {
        resetAndShuffleDeck();
    }
    return deck[deckPos++];
}

int BlackjackModel::rank(int card) { return card % Constants::CARDS_PER_SUIT; }
int BlackjackModel::suit(int card) { return card / Constants::CARDS_PER_SUIT; }

QString BlackjackModel::cardToString(int card) {
    return QString("%1%2").arg(Strings::RANKS[rank(card)]).arg(Strings::SUITS[suit(card)]);
}

int BlackjackModel::handValue(const std::vector<int>& hand) {
    int total = 0;
    int aces = 0;
    for (int c : hand) {
        int r = rank(c);
        int v;
        if (r == 0) { v = 11; ++aces; }
        else if (r >= 10) { v = 10; }
        else { v = r + 1; }
        total += v;
    }
    while (total > 21 && aces > 0) { total -= 10; --aces; }
    return total;
}

BlackjackModel::Outcome BlackjackModel::determineOutcome(int playerVal, int dealerVal) {
    if (playerVal > 21) return Outcome::DealerWin;
    if (dealerVal > 21) return Outcome::PlayerWin;
    if (playerVal > dealerVal) return Outcome::PlayerWin;
    if (playerVal < dealerVal) return Outcome::DealerWin;
    return Outcome::Push;
}

int BlackjackModel::dealerPlay() {
    int val = handValue(dealer);
    while (val < Constants::DEALER_STAND_VALUE) {
        dealer.push_back(draw());
        val = handValue(dealer);
    }
    return val;
}
