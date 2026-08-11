#include <iostream>
using namespace std;
int main(){
    int n; 
    cout << "Enter the value of n to print from 1 to n";
    cin >> n;
   
    for(int i = 0; i < n; i ++){ // outer start
        char ch = 'A';
        for(int j = 0; j < n; j ++){ //inner start
            cout << ch;
            ch = ch + 1;
        }
        cout << endl;
    }
}