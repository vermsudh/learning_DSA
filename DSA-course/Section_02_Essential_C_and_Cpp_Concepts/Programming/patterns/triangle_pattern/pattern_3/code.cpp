#include <iostream>
using namespace std;

int main(){
    int n; 
    cout << "Enter the value of n to print from 1 to n :  ";
    cin >> n;
 
    for(int i = 0; i < n; i++){ // running the first loop from 1 to n (if n = 3, then 0, 1, 2) 3 iteration
        for(int j = 0; j < i + 1; j++){
            cout << "*" << " ";
        }
        cout << endl;
    }
}