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

// merge sort http://www.bogotobogo.com/Algorithms/mergesort.php

vector<string> mergeSort(vector<string> v) {
    if (v.size() <= 1) {
        return v;
    }
    
    int middle = ((int) v.size()+ 1) / 2;
    
    vector<string> left, right, result;
    
    for (int i = 0; i < middle; i++ ) {
        left.push_back(v[i]);
    }
    
    //copy over left and right vectors
    for (int i = middle; i < v.size(); i++ ) {
        right.push_back(v[i]);
    }
    
    left = mergeSort(left);
    right = mergeSort(right);
    // result = std::merge(left, right);
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(result));
    
    return result;
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
    auto start = std::chrono::steady_clock::now();
    vector<string> words = parseFile("../dracula.txt");
    
    // Merge sort
    words = mergeSort(words);
    
    // print out vector
    for (uint i = 0 ; i < words.size(); i++) {
        std::cout << words[i] << std::endl;
    }
    std::cout << "length of vector: " << words.size() << std::endl;
    auto finish = std::chrono::steady_clock::now();
    double elapsed_seconds = std::chrono::duration_cast<
        std::chrono::duration<double> >(finish - start).count();
    std::cout << "time: " << elapsed_seconds << endl;   
    return 0;
}
