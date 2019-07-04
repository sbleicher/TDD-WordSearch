#include <gtest/gtest.h>
#include "word-search.hpp"

TEST(WordSearch, Filename_Test){
  const std::string filename = "master_puzzle.txt";
  WordSearch ws(filename);
  EXPECT_EQ(filename, ws.getFilename());
}

TEST(WordSearch, Get_Words_Test){
  const std::vector<std::string> correctWords = { "BONES", "KHAN", "KIRK", "SCOTTY", "SPOCK", "SULU", "UHURA" };
  const std::string filename = "master_puzzle.txt";
 
  WordSearch ws(filename);
  ws.ReadFile();
  std::vector<Word> words = ws.getWords();

  for(int i = 0; i < correctWords.size(); i++){
    EXPECT_EQ(correctWords[i], words[i].word);
  }
}
