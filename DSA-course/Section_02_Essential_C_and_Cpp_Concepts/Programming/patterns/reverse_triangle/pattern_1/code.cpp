#include <iostream>
using namespace std;

int main(){
    int n; 
    cout << "Enter the value of n to print from 1 to n :  ";
    cin >> n;
    
    for(int i = n; i > 0; i-- ){
        cout << i << endl;
    }
    return 0;
}