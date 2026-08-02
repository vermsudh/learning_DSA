#include <iostream>
using namespace std;
// WAP to check if the num is prime or not? 
int main(){
    // int i;
    // int n;
    // bool isPrime = true ;
    // cout << "Enter the number" << endl;
    // cin >> n;
      
    // for(i = 2; i <= n -1; i++){
    //     if(n % i == 0){
    //         isPrime = false;
    //         break;
    //     }
    // }
    // if(isPrime == true){
    //     cout << "THis is a prime number: ";
    // }
    // else{
    //     cout << "This is not a prime number";
    // }
    // return 0;

        int i;
    int n;
    bool isPrime = true ;
    cout << "Enter the number" << endl;
    cin >> n;
      
    for(i = 2; i *i <= n -1; i++){
        if(n % i == 0){
            isPrime = false;
            break;
        }
    }
    if(isPrime == true){
        cout << "THis is a prime number: ";
    }
    else{
        cout << "This is not a prime number";
    }
    return 0;
}