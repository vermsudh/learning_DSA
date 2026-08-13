#include <iostream>
#include <vector> // when we solve the questions on interview, please use that specific header file
using namespace std;

int main(){

    // vector<int> vec;
    // cout << vec[0]; // we will get an error if we try to print this as the we have not initlized the values
    // // of this vectory above;
    // //error :zsh: segmentation fault  ./a.out

    // vector<int> vec = {1, 3, 4, 5, 6};
    // cout << vec[0];

    vector<int> vec (5, 0);

    // cout << vec[0] << endl;
    // cout << vec[0] << endl;
    // cout << vec[0] << endl;
    // cout << vec[0] << endl;
    // cout << vec[0] << endl;

    vector<char> vec1 = {'a', 'b', 'c', 'd', 'e', 'f'};
    for(char value : vec1){
        cout << value << endl;
    }
    
    return 0;
}
