//
//  main.cpp
//  Sorting
//
//  Created by Danh Nguyen on 4/9/17.
//  Copyright © 2017 Danh Nguyen. All rights reserved.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>


using namespace std;

vector<string> parseFile(string name) {
    vector<string> words;
    ifstream fin;
    fin.open(name);
    string word;
    while (fin >> word) {
        words.push_back(word);
    }
    
    return words;
}

int main() {
    
    vector<string> words = parseFile("../dracula.txt");
    
    // std lib quick sort
       std::sort(words.begin(), words.end());
    
    // print out vector
    for (uint i = 0 ; i < words.size(); i++) {
        std::cout << words[i] << std::endl;
    }
    std::cout << "length of vector: " << words.size() << std::endl;
    return 0;
}
