#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <map>

using namespace std;
void treeOperations(vector<int> arr);

int main(int argc, char *argv[])
{
    int num = 0;
    srand (time(NULL));
    vector<int> arr(1000);
    iota(begin(arr),end(arr),0); //populate with 0...1000
    random_shuffle(arr.begin(),arr.end());
    treeOperations(arr);
    return 0;
}

void treeOperations(vector<int> arr){
    //STL's implmentation of a map is a binary search tree
    map<int,int> tree;
    for(int i = 0; i<1000;i++){
          tree[i] = arr[0];
    }

    //insert
    tree[1000] = 3333;
}
