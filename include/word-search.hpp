#ifndef WORDSEARCH_HPP
#define WORDSEARCH_HPP

#include <string>

class WordSearch 
{ 
    private:
        std::string file;

    public: 
        WordSearch(std::string filename);

        //Get Functions
        std::string getFilename() { return file; }
}; 

WordSearch::WordSearch(std::string filename){
    file = filename;
}

#endif