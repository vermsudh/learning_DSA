#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter a number to check if it is odd or even? \n";
    cin >> n; 
    if(n%2 == 0 ){
        cout << "This is even";
    }else{
        cout << "This is Odd";
    }
    return 0;
}