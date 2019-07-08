#include <gtest/gtest.h>
#include "word-search.hpp"

TEST(WordSearch, Filename_Test){
  const std::string filename = "master_puzzle.txt";
  WordSearch ws(filename);
  EXPECT_EQ(filename, ws.getFilename());
}

TEST(WordSearch, Read_Words_Test){
  const std::vector<std::string> correctWords = { "BONES", "KHAN", "KIRK", "SCOTTY", "SPOCK", "SULU", "UHURA" };
  const std::string filename = "test_data/master_puzzle.txt";
 
  WordSearch ws(filename);
  ws.ReadFile();
  std::vector<Word> words = ws.getWords();

  ASSERT_EQ(correctWords.size(), words.size());

  for(int i = 0; i < correctWords.size(); i++){
    EXPECT_EQ(correctWords[i], words[i].word);
  }
}

TEST(WordSearch, Read_Grid_Test){
  const std::vector<std::vector<char>> correctGrid = { 
    {'U','M','K','H','U','L','K','I','N','V','J','O','C','W','E'},
    {'L','L','S','H','K','Z','Z','W','Z','C','G','J','U','Y','G'},
    {'H','S','U','P','J','P','R','J','D','H','S','B','X','T','G'},
    {'B','R','J','S','O','E','Q','E','T','I','K','K','G','L','E'},
    {'A','Y','O','A','G','C','I','R','D','Q','H','R','T','C','D'},
    {'S','C','O','T','T','Y','K','Z','R','E','P','P','X','P','F'},
    {'B','L','Q','S','L','N','E','E','E','V','U','L','F','M','Z'},
    {'O','K','R','I','K','A','M','M','R','M','F','B','A','P','P'},
    {'N','U','I','I','Y','H','Q','M','E','M','Q','R','Y','F','S'},
    {'E','Y','Z','Y','G','K','Q','J','P','C','Q','W','Y','A','K'},
    {'S','J','F','Z','M','Q','I','B','D','B','E','M','K','W','D'},
    {'T','G','L','B','H','C','B','E','C','H','T','O','Y','I','K'},
    {'O','J','Y','E','U','L','N','C','C','L','Y','B','Z','U','H'},
    {'W','Z','M','I','S','U','K','U','R','B','I','D','U','X','S'},
    {'K','Y','L','B','Q','Q','P','M','D','F','C','K','E','A','B'}
   };
   const std::string filename = "test_data/master_puzzle.txt";
 
  WordSearch ws(filename);
  ws.ReadFile();
  std::vector<std::vector<char>> grid = ws.getGrid();
  
  for(int i = 0; i < correctGrid.size(); i++){
    for(int j = 0; j < correctGrid[i].size(); j++){
      EXPECT_EQ(correctGrid[i][j], grid[i][j]);
    }
  }
}

TEST(WordSearch, Valid_Puzzle_Test){
  const std::string filename1 = "test_data/master_puzzle.txt";
  const std::string filename2 = "test_data/invalid_puzzle.txt";

  WordSearch ws1(filename1);
  ws1.ReadFile();

  WordSearch ws2(filename2);
  ws2.ReadFile();

  EXPECT_EQ(true, ws1.isValidPuzzle());
  EXPECT_EQ(false, ws2.isValidPuzzle());
}

TEST(WordSearch, Words_Fit_Test){
  const std::string filename = "test_data/master_puzzle.txt";
  WordSearch ws(filename);
  ws.ReadFile();

  std::vector<Word> words = ws.getWords();

  bool t1 = ws.checkIfWordFitsInPuzzle(0, 0, 1, 0, words[0]);
  bool t2 = ws.checkIfWordFitsInPuzzle(12, 0, 1, 0, words[0]);

  EXPECT_EQ(true, t1);
  EXPECT_EQ(false, t2);
}

TEST(WordSearch, Horizantal_Forward_Test){
  const std::string filename = "test_data/horizantal_forward.txt";
  const std::vector<std::vector<Position>> correctPositions = { { Position(10,14), Position(11,14), Position(12,14), Position(13,14), Position(14,14) },
    { Position(6,0), Position(7,0), Position(8,0), Position(9,0) },
    { Position(7,10), Position(8,10), Position(9,10), Position(10,10) },
    { Position(0,5), Position(1,5), Position(2,5), Position(3,5), Position(4,5), Position(5,5) } };

  WordSearch ws(filename);
  ws.ReadFile();
  ws.searchPuzzle();
  std::vector<Word> words = ws.getWords();


  ASSERT_EQ(correctPositions.size(), words.size());

  for(int i = 0; i < words.size(); i++){
    ASSERT_EQ(correctPositions[i].size(), words[i].word.size());
  }

  for(int i = 0; i < words.size(); i++){
    for(int j = 0; j < words[i].word.size(); j++){
      EXPECT_EQ(correctPositions[i][j].x, words[i].char_pos[j].x);
      EXPECT_EQ(correctPositions[i][j].x, words[i].char_pos[j].x);
    }
  }
}
