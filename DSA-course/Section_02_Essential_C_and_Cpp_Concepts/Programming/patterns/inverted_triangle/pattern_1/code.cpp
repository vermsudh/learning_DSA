#include <iostream>
using namespace std;

int main(){
    int n; 
    cout << "Enter the value of n to print from 1 to n :  ";
    cin >> n;
    
    for(int i = 0; i < n; i++){
        // this inner loop will print the spaces
        for(int j = 0; j < i; j++){
            cout << " ";    
        }
        //this innner lopp will print the num
        for (int j = 0; j < n-i; j++){
            cout << (i + 1);
        }
        cout << endl;
    }
    return 0;
}