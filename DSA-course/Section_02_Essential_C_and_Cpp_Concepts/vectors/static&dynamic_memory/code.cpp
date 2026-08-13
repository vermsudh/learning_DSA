#include <iostream>
#include <vector> // when we solve the questions on interview, please use that specific header file
using namespace std;

int main(){

    vector<int> vec;

    vec.push_back(0);
    vec.push_back(2);
    vec.push_back(3);

    cout << "Vector Size : " <<  vec.size() << endl;
    cout << "Vector Capacity : " << vec.capacity() << endl;

    return 0;
}
