#include <iostream>
#include <vector>
using namespace std;

int main (){

    vector<int> vec = { 5, 5, 6, 7, 6};

    for(int value1 : vec){
        int count = 0;

        for(int value2 : vec){
            if (value1 == value2){
                count += 1;
            }
        }
        if (count == 1){
            cout << "The single number in this vector is : " << value1;
            return 0;
        }
    }   
    cout << "No Sigle value was being found in this array";

    return -1;
}

