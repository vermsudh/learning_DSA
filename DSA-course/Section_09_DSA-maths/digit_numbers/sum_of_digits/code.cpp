#include<iostream>
#include<vector>
using namespace std;

int sumOfDigits(int n){ // Time complexity of this loop would be O(10 log n) as we are diving the number 10
    int count = 0;

    if(n == 0){
        return 0;
    }
    int sum = 0;
    while(n != 0){
        
        int digit = n % 10; 
        sum += digit;
        n = n / 10;
    }

    return sum;
}
 
int main()
{
    int n; 
    cout << "Type the value of n :o get the count of prime numbers: "<< endl;
    cin >> n;
    cout << "The sum of digits is: " << sumOfDigits(n) << endl;

    return 0;
}