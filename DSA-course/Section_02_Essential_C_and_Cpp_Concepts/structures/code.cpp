#include <iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
    char x; // This will show 4 bytes of memory taken but it will only 1 byte.
};// defining a structure

//You can define the variables outside the main function to make it
// global and be accessible for any function in the file. 

// struct Rectangle r1, r2, r3; 

int main(){
    struct Rectangle r1={10, 5};

    cout << sizeof(r1) << endl; // This will take 4 bytes as int takes 4 buyes
    //total memory will be 8
    cout << r1.length << endl;
    cout << r1.breadth << endl;

    return 0;
}