cmake_minimum_required(VERSION 3.14)

project(HomeWorkSQL LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

find_package(Qt6 REQUIRED COMPONENTS Core Network Sql)

add_executable(HomeWorkSQL
  main.cpp
)
target_link_libraries(HomeWorkSQL Qt${QT_VERSION_MAJOR}::Core)

target_link_libraries(HomeWorkSQL Qt6::Core Qt6::Network Qt6::Sql)

install(TARGETS HomeWorkSQL
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
