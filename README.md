QtJack — Simple Blackjack in C++ with Qt

QtJack is a minimal Blackjack game used to experiment with the Qt Widgets framework in C++. It demonstrates a clean separation between Model, ViewModel, and View, plus a tiny wrapper framework around common Qt widgets.

This repository is intentionally small and easy to build so you can focus on Qt basics and a simple MVVM-ish architecture.

Features
- Classic Blackjack mechanics: hit, stand, dealer draw rules
- Lightweight MVVM structure: Model (game rules), ViewModel (state/commands), View (Qt Widgets UI)
- Plain Qt Widgets (no QML)
- CMake build

Project Layout
- main.cpp — Application entry point and startup
- model/BlackjackModel.* — Core Blackjack state and rules
- viewmodel/BlackjackViewModel.* — Exposes model state and actions to the UI via Qt signals/slots
- view/BlackjackWindow.* — The main game window and controls
- framework/* — Thin wrappers for Qt widgets (Window, Button, Label, Layouts, App)
- common/* — Constants, strings, and basic styling helpers
- CMakeLists.txt — Build configuration

Prerequisites
You need a C++20 compiler, CMake, and Qt5 (Widgets module).

- Linux (Ubuntu):
  - sudo apt update && sudo apt install -y build-essential cmake qtbase5-dev

Build and Run
These commands assume an out-of-source build. From the repository root:

- Linux/macOS:
  - mkdir -p build && cd build
  - cmake ..
  - cmake --build . -j
  - ./QtJack

Gameplay and Controls
- New round starts with initial deal
- Hit: deal another card to the player
- Stand: end player turn; dealer draws according to rules
- Outcome is shown when the round ends; start a new round to play again

Architecture Notes
- Model (model/BlackjackModel.*): Implements the game rules and state transitions
- ViewModel (viewmodel/BlackjackViewModel.*): Bridges Model and View using Qt signals/slots, exposes bindable properties and commands
- View (view/BlackjackWindow.*): Qt Widgets UI for displaying hands, totals, and buttons
- Framework (framework/*): Small convenience wrappers around QWidget, layouts, labels, and buttons to keep view code concise

This separation aims to keep UI code minimal while allowing unit-testable logic in the Model/ViewModel.

