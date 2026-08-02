#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter a number to check if it is + of -ve? \n";
    cin >> n; 
    cout << (n > 0 ? "positive" : "negative") << endl;
    return 0;
}