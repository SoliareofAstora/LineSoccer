cmake_minimum_required(VERSION 3.17)
set(PROJECT_NAME LineSoccer)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

file(GLOB source_files
        "src/**.cpp"
        "include/**.h"
        )

set(SOURCES ${source_files})

find_package(SFML 2 REQUIRED COMPONENTS audio graphics window system)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE "include" "lib")

target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio)
