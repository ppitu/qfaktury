cmake_minimum_required(VERSION 3.14)

project(qfaktury-test LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(qfaktury-test main.cc)

add_subdirectory(MoneyTest)

include_directories("../qfaktury-core")

target_link_libraries(qfaktury-test PRIVATE Qt${QT_VERSION_MAJOR}::Test)
target_link_libraries(qfaktury-test PRIVATE qfaktury-core)

