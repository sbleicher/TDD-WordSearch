cmake_minimum_required (VERSION 3.5)

add_definitions(-std=c++11)

add_subdirectory(lib/googletest-release-1.8.1)

include_directories(include)

# Create a list of files to copy
set( THIRD_PARTY_DLLS
   ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_data/master_puzzle.txt
)

# Copy test text files
foreach( file_i ${THIRD_PARTY_DLLS})
    file(COPY ${file_i}
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/test_data)
endforeach( file_i )

# Locate GTest
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(wordSearchTests tests/word-search.tests.cpp)
target_link_libraries(wordSearchTests gtest gtest_main)
add_test( wordSearchTests wordSearchTests )