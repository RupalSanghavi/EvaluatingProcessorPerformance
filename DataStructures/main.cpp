#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>


using namespace std;
void listOperations(vector<int> arr);
void hashOperations(vector<int> arr);
int main(int argc, char *argv[])
{
    int num = 0;
    srand (time(NULL));
    vector<int> arr(1000);
    iota(begin(arr),end(arr),0); //populate with 0...1000
    random_shuffle(arr.begin(),arr.end());
    listOperations(arr);
    hashOperations(arr);
    return 0;
}
void listOperations(vector<int> arr){
//    int num = 0;
//    srand (time(NULL));
//    vector<int> arr;
//    for(int i = 0; i<1000;i++){
//          num = rand() % 100 + 1;
//          arr.push_back(num);
//    }
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
    for(int i = 0; i<1000;i++){
          hash[i] = arr[0];
    }
    //search
    unordered_map<int,int>::const_iterator got = hash.find(444);
    if (got == hash.end() )
        std::cout << "Not Found";
    else
        std::cout << got->first << " is " << got->second;
}
