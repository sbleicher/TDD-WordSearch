#include "word_search.hpp"

int main(){
  const std::string filename = "test_data/master_puzzle.txt";

  WordSearch ws(filename);
  ws.ReadFile();
  ws.searchPuzzle();
  ws.printResults();

  return 0;
}