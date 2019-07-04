#ifndef WORDSEARCH_HPP
#define WORDSEARCH_HPP

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

struct Position{
    int x, y;
};

struct Word{
    public:
        std::string word;
        std::vector<Position> char_pos;
};

class WordSearch 
{ 
    private:
        std::string file;
        std::vector<Word> words;
        std::vector<std::vector<char>> grid;

    public: 
        WordSearch(std::string filename);
        void ReadFile();

        //Get Functions
        std::string getFilename() { return file; }
        std::vector<Word> getWords() { return words; }
        std::vector<std::vector<char>> getGrid() { return grid; }
}; 

WordSearch::WordSearch(std::string filename){
    file = filename;
}

void WordSearch:: ReadFile(){
    std::ifstream infile(file);

    int line_count = 0;
    std::string line;
    while (std::getline(infile, line))
    {
        if(line_count != 0){ grid.push_back(std::vector<char>()); }

        std::stringstream tempLine(line);
        std::string line_segment;
        while(std::getline(tempLine, line_segment, ','))
        {
            if(line_count == 0){
                Word tempWord;
                tempWord.word = line_segment;
                words.push_back(tempWord);
            }
            else{
                grid[line_count - 1].push_back(line_segment[0]);
            }
        }
        line_count++;
    }
}

#endif