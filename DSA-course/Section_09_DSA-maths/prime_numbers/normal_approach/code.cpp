#include<iostream>
#include<vector>
using namespace std;

string checkPrime(int n){
    for(int i = 0; i * i <=n; i++){
        if(n % 2 == 0){
            return "not a prime number";
        }
    }
    return "Prime number";
}
 
int main()
{
    
    int n;

    while(n != 0){
        
        cout << "Please type a number to check if the num is prime of not." << endl;
        cin >> n;
        cout << checkPrime(n) << endl;
    }

    return 0;
}