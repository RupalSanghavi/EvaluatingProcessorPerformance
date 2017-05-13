#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <map>

using namespace std;
void hashOperations(vector<int> arr);

int main(int argc, char *argv[])
{
    int num = 0;
    srand (time(NULL));
    vector<int> arr(1000);
    iota(begin(arr),end(arr),0); //populate with 0...1000
    random_shuffle(arr.begin(),arr.end());
    hashOperations(arr);
    return 0;
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

}

