#include <iostream>
#include <vector> // when we solve the questions on interview, please use that specific header file
using namespace std;

int main(){

    vector<int> vec;
    cout << "Size of the vector is : " << vec.size() << endl; 
    vec.push_back(25); // This function helps use to increase the size of the vector.
    vec.push_back(30); 
    vec.push_back(40);
    cout << "After the push back , Size of the vector is : " << vec.size() << endl; 
    vec.pop_back(); // This deletes the element from the vector and it always delete the value from the last
                    // index
    vec.front(); // This helps us to print the value of the frist element
    cout << " Front value of this vector: "<<vec.front() << endl;
    vec.back(); // prints the value of the last element in the vector.
    vec.at(0); // This will print the value of the index that we are going to pass in the vector. 
    for(int value : vec){
        cout << value << endl;
    }
    return 0;
}
