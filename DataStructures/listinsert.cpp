#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <map>

using namespace std;
void listOperations(vector<int> arr);

int main(int argc, char *argv[])
{
    int num = 0;
    srand (time(NULL));
    vector<int> arr(1000);
    iota(begin(arr),end(arr),0); //populate with 0...1000
    random_shuffle(arr.begin(),arr.end());
    listOperations(arr);
    return 0;
}
void listOperations(vector<int> arr){

    vector<int>::iterator it;
    it = arr.begin();
    arr.insert(it,845,44);

}
