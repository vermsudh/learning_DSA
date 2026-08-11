#include <iostream>
using namespace std;

int main(){
    int n; 
    cout << "Enter the value of n to print from 1 to n :  ";
    cin >> n;
 
    char ch = 'A';

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ch << " ";
            ch +=1;
        }
        cout << endl;
    }
    return 0;
}


