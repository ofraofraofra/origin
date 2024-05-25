cmake_minimum_required(VERSION 3.20)

project(sqlproject)

set(LIBPQXX_SOURCE_DIR "C:/Users/ofrao/Desktop/libpqxx")

add_subdirectory(${LIBPQXX_SOURCE_DIR} libpqxx-build)

add_executable(sqlproject source.cpp)

target_compile_features(sqlproject PRIVATE cxx_std_17)

target_include_directories(sqlproject PRIVATE ${LIBPQXX_SOURCE_DIR}/include)

target_link_libraries(sqlproject PRIVATE pqxx)
