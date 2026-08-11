#include <iostream>
using namespace std;
// WAP to print sum of 1 to n which are odd nums
int main(){

    int i = 1;
    int sum =0;
    int n;
    cout << "Enter a number to print odd nums from 1 to n : \n";
    cin >> n;
    for(int i; i <=n; i++){
        if(i%2 != 0){
            cout << i << " " << endl;
            sum = sum + i;
        }   
    }
    cout << "Sum of 1 to n of all odd nums :" << sum;
    return 0;
}