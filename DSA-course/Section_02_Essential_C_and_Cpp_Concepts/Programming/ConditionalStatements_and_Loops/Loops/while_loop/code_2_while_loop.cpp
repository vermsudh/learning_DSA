#include <iostream>
using namespace std;

int main(){
   int n;
   cout << "Enter the value of n to print from 1 to n: \n" << endl;
   cin >> n;
   int i = 1;
   while ( i <= n){
        cout << i << " ";
        i++;
   }
   return 0;
}