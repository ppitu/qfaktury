cmake_minimum_required(VERSION 3.14)

project(qfaktury-core LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Sql REQUIRED)

file(GLOB_RECURSE source_class Class/*.cpp Class/*.h)
file(GLOB_RECURSE source_exception Exception/*.cpp Exception/*.h)
file(GLOB_RECURSE source_model Model/*.cpp Model/*.h)
file(GLOB_RECURSE source_type_class TypeClass/*.cpp TypeClass/*.h)

add_library(qfaktury-core SHARED
  qfaktury-core_global.h
  ${source_class}
  ${source_exception}
  ${source_model}
  ${source_type_class}
)

add_subdirectory(Database)
add_subdirectory(DatabaseClass)
add_subdirectory(Class)
add_subdirectory(Model)
add_subdirectory(Money)
add_subdirectory(Exception)

target_link_libraries(qfaktury-core PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(qfaktury-core PRIVATE QFAKTURYCORE_LIBRARY)
target_link_libraries(qfaktury-core PRIVATE Qt${QT_VERSION_MAJOR}::Sql)

target_compile_definitions(qfaktury-core PRIVATE QFAKTURYCORE_LIBRARY)
