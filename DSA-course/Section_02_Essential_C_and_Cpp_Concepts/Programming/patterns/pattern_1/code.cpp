#include <iostream>
using namespace std;

int main(){

    int n; 
    cout << "Eneter the value of n to print from 1 to n";
    cin >> n;

    for(int i = 1; i <=n; i++){ // outer loop which will print from 1 to n (to print the rows)
        for(int j = 1; j<= n; j++){ // inner loop to print the coulmns
            cout << j;
        }
        cout << endl; // This line will help to leave line once the inner loop finish and write the second 
                        // iteration on the next line until the inner loop is iterated propertly.
    }
}