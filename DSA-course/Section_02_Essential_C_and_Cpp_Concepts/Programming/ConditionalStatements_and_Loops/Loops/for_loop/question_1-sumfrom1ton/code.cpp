#include <iostream>
using namespace std;
// WAP to sum from 1 to n using for loop
int main(){
   int n, i;
   int sum = 0;
   cout << "Enter the value of n \n" << endl;
   cin >> n;
   for(i = 1; i <= n; i++){
        sum = sum + i;
   }
   cout << "Sum of 1 to n is : " << sum << endl;
   return sum;
}