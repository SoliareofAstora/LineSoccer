cmake_minimum_required(VERSION 3.17)
project(LineSoccer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_library(LS_module
        player/AgentLogic.cpp
        player/AgentLogic.h
        visualization/Button.h
        utils/Debug.cpp
        field/old_FieldLogic.cpp
        field/old_FieldLogic.h
        visualization/FieldVisualization.cpp
        visualization/FieldVisualization.h
        player/FullTreeAgent.cpp
        player/FullTreeAgent.h
        logic/GameLogic.cpp
        logic/GameLogic.h
        input_handler/InputController.cpp
        input_handler/InputController.h
        utils/LinkedList.cpp
        utils/LinkedList.h
        field/MapNode.h
        logic/Move.h
        utils/node.h
        player/Player.h
        player/RandomAgent.cpp
        player/RandomAgent.h
        utils/stack.cpp
        utils/stack.h
        input_handler/UI.cpp
        input_handler/UI.h
        visualization/visualization.cpp
        visualization/visualization.h
        field/field_logic.hpp utils/bit_set.hpp)

target_link_libraries(LS_module
        -lsfml-graphics
        -lsfml-window
        -lsfml-system
)

add_executable(LineSoccer main.cpp)

target_link_libraries(LineSoccer LS_module)