#include <iostream>
using namespace std;


int main(){

    int a, b;

    a = 10;
    b = a++; // In this a = 11, b =10  becasue this
    //post increment operator which acts 
    // once the value has been assigned.

    cout << "Value of a : " << a << endl;
    cout << "Value of b : " << b << endl;

    int c = 10;
    int d = --c;
    // ++c is pre increment. First the value will
    // be added and then it will get assigned.

    cout << "Value of c : " << c << endl;
    cout << "Value of d : " << d << endl;
}