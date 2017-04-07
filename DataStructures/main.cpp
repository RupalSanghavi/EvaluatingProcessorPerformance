#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <map>

using namespace std;
void listOperations(vector<int> arr);
void hashOperations(vector<int> arr);
void treeOperations(vector<int> arr);

int main(int argc, char *argv[])
{
    int num = 0;
    srand (time(NULL));
    vector<int> arr(1000);
    iota(begin(arr),end(arr),0); //populate with 0...1000
    random_shuffle(arr.begin(),arr.end());
    listOperations(arr);
    hashOperations(arr);
    treeOperations(arr);
    return 0;
}
void listOperations(vector<int> arr){
    int search = rand() % 100 + 1;
    //search
    for(int i = 0; i<1000; i++){
         if(arr[i] == search){
                 cout<<"Found";
                 break;
             }
     }
    //insert
    vector<int>::iterator it;
    it = arr.begin();
    arr.insert(it,845,44);
    //delete
    arr.erase(arr.begin()+45);

}
void hashOperations(vector<int> arr){
    unordered_map<int,int> hash;
    //initialize hash
    for(int i = 0; i<1000;i++){
          hash[i] = arr[0];
    }
    //search
    unordered_map<int,int>::const_iterator got = hash.find(444);
    if (got == hash.end() )
        std::cout << "Not Found";
    else
        std::cout << got->first << " is " << got->second;
    //insert
    hash[1000] = 5555;
    //delete
    hash.erase(777);
}
void treeOperations(vector<int> arr){
    //STL's implmentation of a map is a binary search tree
    map<int,int> tree;
    for(int i = 0; i<1000;i++){
          tree[i] = arr[0];
    }
    //search
    map<int,int>::const_iterator got = tree.find(444);
    if (got == tree.end() )
        std::cout << "Not Found";
    else
        std::cout << got->first << " is " << got->second;
    //insert
    tree[1000] = 3333;
    //delete
    tree.erase(345);
}
