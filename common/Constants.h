#pragma once

namespace Constants {
// Gameplay and UI constants
inline constexpr int INITIAL_CHIPS = 100;
inline constexpr int FIXED_BET = 10;

inline constexpr int WINDOW_WIDTH = 500;
inline constexpr int WINDOW_HEIGHT = 500;

// Deck/card structure
inline constexpr int SUIT_COUNT = 4;
inline constexpr int CARDS_PER_SUIT = 13;
inline constexpr int NUM_RANKS = CARDS_PER_SUIT; // 13 ranks A..K
inline constexpr int DECK_SIZE = SUIT_COUNT * CARDS_PER_SUIT; // 52

// Dealer and shoe behavior
inline constexpr int DEALER_STAND_VALUE = 17; // Dealer hits until 17+
inline constexpr int RESHUFFLE_THRESHOLD = 40; // When deckPos > 40, reshuffle
}
