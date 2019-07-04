#include <gtest/gtest.h>
#include "word-search.hpp"

TEST(WordSearch, Filename_Test){
  const std::string filename = "master_puzzle.txt";
  WordSearch ws(filename);
  EXPECT_EQ(filename, ws.getFilename());
}
