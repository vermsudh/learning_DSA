#include <iostream>
using namespace std;

int sum(int a, int b){
    a = a + 10;
    b = b + 20;

    return a + b;
}

int changeX(int x){
    x = 2 * x;
    cout << "x = " << x << endl;

    return x;
}

int main(){
    int a = 5, b = 4;

    int  x = 25;
    changeX(x);
    cout << "x = " << x << endl;
    // cout << sum(5, 4) << endl;

    // cout << a << endl;
    // cout << b << endl;

    return 0;
}

// We can try to understand the pass by value like this
// if we have stored varibales in a function and we are calling that function in our main function
// then we are not going to get the same values of the variables that we have used in the function
// THe calling function will have a new values of its own.

// In case of Pass by reference, then we pass the address of the function as well. 