#include <iostream>
using namespace std;

int main(){
    int n; 
    cout << "Enter the value of n to print from 1 to n :  ";
    cin >> n;
    int num = 1;
    char ch = 'A';

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i + 1; j ++){
            cout << ch;
            ch ++;
        }
       cout << endl;
    }
    return 0;
}
