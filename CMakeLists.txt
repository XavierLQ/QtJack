cmake_minimum_required(VERSION 4.0)
project(QtJack)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)
add_executable(QtJack
        main.cpp
        model/BlackjackModel.cpp
        viewmodel/BlackjackViewModel.cpp
        view/BlackjackWindow.cpp
)
target_link_libraries(QtJack
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

# Make headers discoverable without changing include paths
target_include_directories(QtJack PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/model
        ${CMAKE_CURRENT_SOURCE_DIR}/viewmodel
        ${CMAKE_CURRENT_SOURCE_DIR}/view
        ${CMAKE_CURRENT_SOURCE_DIR}/framework
        ${CMAKE_CURRENT_SOURCE_DIR}/common
)

