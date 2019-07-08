#ifndef WORDSEARCH_HPP
#define WORDSEARCH_HPP

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

struct Position{
    int x, y;

    Position(int xVal, int yVal){
        x = xVal;
        y = yVal;
    }
};

typedef Position Slope;

struct Word{
    std::string word;
    std::vector<Position> char_pos;
    bool found;
};

class WordSearch 
{ 
    private:
        std::string file;
        std::vector<Word> words;
        std::vector<std::vector<char>> grid;
        std::vector<Slope> slopes = { 
            Slope(1, 0), //Horizantal Forward
            Slope(-1, 0), //Horizantal Backward
            Slope(0, 1), //Vertical Forward
            Slope(0, -1), //Vertical Backwards
            Slope(-1, 1), //Diagonally Descending Left
            Slope(1, 1) //Diagonally Descending Right
        };

    public: 
        WordSearch(std::string filename);
        void ReadFile();
        bool isValidPuzzle();
        bool checkIfWordFitsInPuzzle(int posX, int posY, int slopeX, int slopeY, Word word);
        void checkForWord(int x, int y, int slopeX, int slopeY);
        void searchPuzzle();

        //Get Functions
        std::string getFilename() { return file; }
        std::vector<Word> getWords() { return words; }
        std::vector<std::vector<char>> getGrid() { return grid; }
}; 

WordSearch::WordSearch(std::string filename){
    file = filename;
}

void WordSearch::ReadFile(){
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
                tempWord.found = false;
                words.push_back(tempWord);
            }
            else{
                grid[line_count - 1].push_back(line_segment[0]);
            }
        }
        line_count++;
    }
}

bool WordSearch::isValidPuzzle(){
    
    if(grid.size() == 0){ return false; }
    
    int gridLength = grid[0].size();
    for(int i = 0; i < grid.size(); i++){
        if(grid[i].size() != gridLength){ return false; }
    }

    return true;
}

bool WordSearch::checkIfWordFitsInPuzzle(int posX, int posY, int slopeX, int slopeY, Word word){
    int wordSize = word.word.size();
    int xDisplacement = posX + slopeX * (wordSize - 1);
    int yDisplacement = posY + slopeY * (wordSize - 1);

    //Checks if word will be outside for X value
    if(xDisplacement < 0 || xDisplacement >= grid[0].size()){
        return false;
    }

    //Checks if word will be outside for Y value
    if(yDisplacement < 0 || yDisplacement >= grid.size()){
        return false;
    }

    return true;
}

void WordSearch::checkForWord(int x, int y, int slopeX, int slopeY){
    for(int i = 0; i < words.size(); i++){
        if(!words[i].found && words[i].word[0] == grid[y][x] && checkIfWordFitsInPuzzle(x, y, slopeX, slopeY, words[i])){
            bool validated = true;
            for(int j = 1; j < words[i].word.size(); j++){
                if(words[i].word[j] != grid[y + j * slopeY][x + j * slopeX]){
                    validated = false; 
                    break;
                }
            }

            if(validated){
                words[i].found = true;
                for(int j = 0; j < words[i].word.size(); j++){
                    Position tPos(x + j * slopeX, y + j * slopeY);
                    words[i].char_pos.push_back(tPos);
                }
            }
        }
    }
}

void WordSearch::searchPuzzle(){
    for(int y = 0; y < grid.size(); y++){
        for(int x = 0; x < grid[y].size(); x++){
            for(int s = 0; s < slopes.size(); s++){
                checkForWord(x, y, slopes[s].x, slopes[s].y);
            }
        }
    }
}

#endif