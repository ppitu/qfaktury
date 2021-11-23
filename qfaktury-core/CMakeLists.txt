cmake_minimum_required(VERSION 3.14)

project(qfaktury-core LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Sql REQUIRED)

add_library(qfaktury-core SHARED
  qfaktury-core_global.h
  Database/DatabaseManager.h Database/DatabaseManager.cpp
  Class/Product.h Class/Product.cpp
  DatabaseClass/ProductDao.h DatabaseClass/ProductDao.cpp
  Model/ProductModel.h Model/ProductModel.cpp
)

target_link_libraries(qfaktury-core PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(qfaktury-core PRIVATE QFAKTURYCORE_LIBRARY)
target_link_libraries(qfaktury-core PRIVATE Qt${QT_VERSION_MAJOR}::Sql)

target_compile_definitions(qfaktury-core PRIVATE QFAKTURYCORE_LIBRARY)
