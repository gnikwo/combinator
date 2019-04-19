#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::string;
    
vector<vector<string>> wordlists;

vector<string> recur(vector<vector<string>>::iterator current) {
    if(current + 1 == wordlists.end())
        return *current;
    
    vector<string> ends = recur(current + 1);
    vector<string> result;
    for(auto word: *current) {
        for(auto end: ends) {
            result.push_back(word + end);
        }
    }
    return result;
}

int main(int argc, char** argv) {
    
    for(int i = 1; i < argc; i++) {
        std::ifstream infile(argv[i]);
        string line;
        vector<string> words;
        while (std::getline(infile, line)) {
            words.push_back(line); 
        }
        wordlists.push_back(words);
    }

    vector<string> dict = recur(wordlists.begin());
    for(auto word: dict) {
        cout << word << endl;
    }

    return 0;
}
