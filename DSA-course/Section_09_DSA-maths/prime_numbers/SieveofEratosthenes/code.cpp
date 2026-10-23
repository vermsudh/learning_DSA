#include<iostream>
#include<vector>
using namespace std;

// Find out the count of of prime numbers from 1 to N. Where is N will be the input given by the user in O(n) TC.
int countPrimes(int n){
    vector<bool> isPrime(n +1, true);

    int count = 0;
    for(int i = 2; i < n; i++){//starting the loop from 2 as 0 and 1 are not prime numbers
        if(isPrime[i]){
            count++;
        }
        for(int j =  i * 2; j < n; j = j + i){
            isPrime[j] = false;
        }
    }
}
 
int main()
{
    int n; 

    cout << "Type the value of n :o get the count of prime numbers: "<< endl;
    n = 20;

    cout << countPrimes(n) << endl;

    return 0;
}