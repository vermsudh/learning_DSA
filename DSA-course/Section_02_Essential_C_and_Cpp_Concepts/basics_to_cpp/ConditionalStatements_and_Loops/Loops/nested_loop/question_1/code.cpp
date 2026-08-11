#include <iostream>
using namespace std;
// WAP to print * using nested loops using the input from the user
// ******
// ******
// ******
// ******
// ******
int main(){

    int n;
    cout << "Enter a value of n : " << endl;
    cin >> n;

    for(int i = 1; i <= n; i++){ // row print
        for(int j = 1; j <= n; j ++){
            cout << "*";
        }
        cout << endl; // this helps to pring the row in seperate line instead of one line print
    }
}
