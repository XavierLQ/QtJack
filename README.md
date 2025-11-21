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

- Linux (Debian/Ubuntu):
  - sudo apt update && sudo apt install -y build-essential cmake qtbase5-dev
- Fedora:
  - sudo dnf install -y gcc-c++ cmake qt5-qtbase-devel
- Arch:
  - sudo pacman -S --needed base-devel cmake qt5-base
- macOS:
  - brew install cmake
  - brew install qt@5
  - You may need to set CMAKE_PREFIX_PATH to Homebrew’s Qt5, for example:
    - export CMAKE_PREFIX_PATH="$(brew --prefix qt@5)"
- Windows:
  - Option A (Qt Creator): Install Qt 5.x with Qt Creator, open this folder, configure, and build.
  - Option B (CMake + MSVC/MinGW): Install Qt 5.x, ensure qmake/Qt5 cmake packages are in CMAKE_PREFIX_PATH.

Build and Run
These commands assume an out-of-source build. From the repository root:

- Linux/macOS:
  - mkdir -p build && cd build
  - cmake ..
  - cmake --build . -j
  - ./QtJack

- Windows (PowerShell, Developer Prompt):
  - mkdir build; cd build
  - cmake .. -G "Ninja"  # or omit -G to use default generator
  - cmake --build . --config Release
  - .\\Release\\QtJack.exe  # or .\\QtJack.exe depending on generator/config

If CMake cannot locate Qt5, set CMAKE_PREFIX_PATH to your Qt installation prefix. Examples:
- Linux: export CMAKE_PREFIX_PATH=/usr/lib/x86_64-linux-gnu/cmake
- macOS (Homebrew Qt5): export CMAKE_PREFIX_PATH="$(brew --prefix qt@5)"
- Windows: set CMAKE_PREFIX_PATH=C:\\Qt\\5.15.2\\msvc2019_64\\lib\\cmake

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

Troubleshooting
- CMake can’t find Qt5:
  - Ensure Qt5 is installed (Widgets module) and set CMAKE_PREFIX_PATH to the Qt cmake package directory.
- Linker errors about Qt symbols:
  - Make sure you’re linking against the same Qt you compiled against; clean the build directory and reconfigure.
- Build errors about CMake version:
  - If your CMake is older than the one required in CMakeLists.txt, update CMake (or adjust the minimum version if you know what you’re doing).

Contributing
Issues and small PRs are welcome. This is a learning project; clarity and simplicity are preferred over feature completeness.

License
No license file is provided. Treat this as read-only unless you obtain permission from the author to reuse or redistribute.
