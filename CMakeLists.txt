cmake_minimum_required (VERSION 3.5)

add_definitions(-std=c++11)

add_subdirectory(lib/googletest-release-1.8.1)

include_directories(include)
include_directories(tests/test_data)

# Locate GTest
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(wordSearchTests tests/word-search.tests.cpp)
target_link_libraries(wordSearchTests gtest gtest_main)
add_test( wordSearchTests wordSearchTests )