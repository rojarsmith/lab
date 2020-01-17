cmake_minimum_required(VERSION 3.5)

project(lab-ccpp-qt-basic-topic LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)

add_executable(lab-ccpp-qt-basic-topic main.cpp rwlock.cpp)
target_link_libraries(lab-ccpp-qt-basic-topic Qt5::Core)
