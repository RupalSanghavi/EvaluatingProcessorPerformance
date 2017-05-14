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

// http://www.algolist.net/Algorithms/Sorting/Quicksort
void quickSort(vector<string>& v, int begin, int end) {
    int i = begin, j = end;
    string temp;
    string pivot = v[(begin + end)/2];
    
    while (i <= j) {
        while (v[i] < pivot) {
            i++;
        }
        while (v[j] > pivot) {
            j--;
        }
        if (i <= j) {
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
    }
    
    if (begin < j) {
        quickSort(v, begin, j);
    }
    if (end > i) {
        quickSort(v, i, end);
    }
}

void quickSort(vector<string>& v) {
    quickSort(v, 0, (int)v.size()-1);
}


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
    
    // Middle pivot quick sort
    quickSort(words);
    
    // print out vector
    for (uint i = 0 ; i < words.size(); i++) {
        std::cout << words[i] << std::endl;
    }
    std::cout << "length of vector: " << words.size() << std::endl;
    return 0;
}
