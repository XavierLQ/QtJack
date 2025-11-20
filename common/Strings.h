#pragma once

#include <QString>
#include <QStringList>

namespace Strings {
// App/window
inline const QString WINDOW_TITLE = QStringLiteral("QtJack — Blackjack");
// Generic
inline const QString EMPTY = QStringLiteral("");

// Section titles
inline const QString DEALER_TITLE = QStringLiteral("Dealer");
inline const QString PLAYER_TITLE = QStringLiteral("Player");

// Buttons
inline const QString BTN_DEAL = QStringLiteral("Deal");
inline const QString BTN_HIT = QStringLiteral("Hit");
inline const QString BTN_STAND = QStringLiteral("Stand");

// Status / messages
inline const QString STATUS_START = QStringLiteral("Press Deal to start a round.");
inline const QString STATUS_CHOOSE = QStringLiteral("Choose Hit or Stand.");
inline const QString STATUS_DREW = QStringLiteral("You drew a card. Hit or Stand?");
inline const QString STATUS_OUT_OF_CHIPS = QStringLiteral("You are out of chips. Restart the app to play again.");
inline const QString STATUS_PLAY_AGAIN_SUFFIX = QStringLiteral(" Press Deal to play again.");

// Outcomes
inline const QString MSG_PLAYER_WIN = QStringLiteral("You win!");
inline const QString MSG_DEALER_WIN = QStringLiteral("Dealer wins.");
inline const QString MSG_PUSH = QStringLiteral("Push (tie).");
inline const QString MSG_BUST_DEALER_WINS = QStringLiteral("Bust! Dealer wins.");

// Formats
inline const QString FMT_TOTAL = QStringLiteral("Total: %1");
inline const QString FMT_TOTAL_WITH_HIDDEN = QStringLiteral("Total: %1 (+ hidden)");
inline const QString FMT_CHIPS = QStringLiteral("Chips: %1    Bet per round: %2");

// Cards
inline const QString HIDDEN_CARD = QStringLiteral("??");
inline const QStringList RANKS = {QStringLiteral("A"), QStringLiteral("2"), QStringLiteral("3"), QStringLiteral("4"), QStringLiteral("5"), QStringLiteral("6"), QStringLiteral("7"), QStringLiteral("8"), QStringLiteral("9"), QStringLiteral("10"), QStringLiteral("J"), QStringLiteral("Q"), QStringLiteral("K")};
inline const QStringList SUITS = {QStringLiteral("♠"), QStringLiteral("♥"), QStringLiteral("♦"), QStringLiteral("♣")};
}
