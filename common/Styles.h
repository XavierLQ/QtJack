#pragma once

#include <QString>

namespace Styles {
// Centralized Qt stylesheet snippets used in the UI
inline const QString TITLE_LABEL = QStringLiteral("font-weight: bold; font-size: 18px");
inline const QString STATUS_LABEL = QStringLiteral("font-size: 14px; color: #333");
inline const QString CHIPS_LABEL = QStringLiteral("font-weight: bold; color: #006400");

// Spacing and layout constants
inline constexpr int ROOT_SPACING = 12;          // QVBoxLayout spacing for root
inline constexpr int ROOT_MARGIN = 12;           // Root contents margins (all sides)
inline constexpr int MID_SPACING = 24;           // Space between dealer and player columns
inline constexpr int CONTROLS_SPACING = 8;       // Spacing between control buttons
inline constexpr int ROOT_SECTION_SPACING = 8;   // Spacing between mid area and status/chips
}
