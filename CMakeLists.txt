cmake_minimum_required(VERSION 3.12)
project("UrlParserCXX")

set(CMAKE_CXX_STANDARD 11)

enable_testing()

add_subdirectory(googletest)

add_executable(UrlParser gtests.cpp UrlParser.cpp)
target_link_libraries(UrlParser gtest gtest_main)
