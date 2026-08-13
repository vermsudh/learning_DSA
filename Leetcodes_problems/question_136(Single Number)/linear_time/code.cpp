#include <iostream>
#include <vector>
using namespace std;

// More optimized way to solve this problem would be using BIT operation, speacifically : XOR



int main (){

    vector<int> vec = { 5, 5, 6, 7, 6};
    int unique =0;
    for(int i = 0; i < vec.size(); i++){
        // We are going to take XOR of each value in this vector
        
        unique ^= i; // This will cancel all the duplicates
    }

    cout << unique;

    return 0;
 
}

