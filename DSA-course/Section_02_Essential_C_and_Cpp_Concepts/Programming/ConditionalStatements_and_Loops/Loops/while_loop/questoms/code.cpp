#include <iostream>
using namespace std;
// WAP to print sum of 1 to n which are odd nums
int main(){

    int i = 1;
    int sum =0;
    int n;
    cout << "Enter a number to print odd nums from 1 to n : \n";
    cin >> n;
    while(i <=n){
        if(i %2 != 0){
            sum += i;
        }
        i++;
    }
    cout << "THe sum of odd nus from 1 to n is : " << sum;
    return 0;
}