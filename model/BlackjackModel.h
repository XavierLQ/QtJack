#pragma once

#include <QObject>
#include <QString>
#include "Constants.h"
#include <vector>

class BlackjackModel : public QObject {
    Q_OBJECT
public:
    explicit BlackjackModel(QObject* parent = nullptr);

    // State
    std::vector<int> deck; // 0..51
    int deckPos = 0;
    std::vector<int> player;
    std::vector<int> dealer;
    bool roundActive = false;
    bool dealerHoleRevealed = false;
    int chips = Constants::INITIAL_CHIPS; // initial chips
    const int bet = Constants::FIXED_BET; // fixed bet per round

    // Utilities / rules
    void resetAndShuffleDeck();
    int draw();

    static int rank(int card);
    static int suit(int card);
    static QString cardToString(int card);
    static int handValue(const std::vector<int>& hand);

    enum class Outcome { PlayerWin, DealerWin, Push };

    static Outcome determineOutcome(int playerVal, int dealerVal);

    // Dealer hits to 17+
    int dealerPlay();
};
