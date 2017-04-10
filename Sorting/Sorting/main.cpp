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


using namespace std;

// http://www.algolist.net/Algorithms/Sorting/quickSort
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


// merge sort http://www.bogotobogo.com/Algorithms/mergesort.php
// returning new vector

vector<string> merge(vector<string>& left, vector<string>& right) {
    vector<string> result;
    while (left.size() > 0 || right.size() > 0) {
        if (left.size() > 0 && right.size() > 0) {
            if ((string)left.front() <= (string)right.front()) {
                result.push_back((string)left.front());
                left.erase(left.begin());
            }
            
            else {
                result.push_back((string)right.front());
                right.erase(right.begin());
            }
        }
        
        // copy leftover left
        else if (left.size() > 0) {
            for (int i = 0; i < (int)left.size(); i++)
                result.push_back(left[i]);
            break;
        }
        
        //copy leftover right
        else if (right.size() > 0) {
            for (int i = 0; i < (int)right.size(); i++)
                result.push_back(right[i]);
            break;
        }
    }
    return result;
}


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
    result = merge(left, right);
    
    return result;
}



int main() {
    vector<string> a = {"hello", "book", "world", "computer", "architecture"};
    
    // Middle pivot quick sort
    //     quickSort(a);
    
    // Merge sort
    a = mergeSort(a);
    
    // std lib quick sort
    //    std::sort(a.begin(), a.end());
    
    // print out vector
    for (uint i = 0 ; i < a.size(); i++) {
        std::cout << a[i] << std::endl;
    }
    return 0;
}
