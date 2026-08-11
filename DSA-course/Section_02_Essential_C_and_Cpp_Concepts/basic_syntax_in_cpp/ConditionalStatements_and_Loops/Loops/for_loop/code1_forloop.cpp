#include <iostream>
using namespace std;

int main(){
   int n;
   cout << "Enter the value of n to print from 1 to n: \n" << endl;
   cin >> n;
   for(int i = 1; i <= n; i++){
        cout << i << endl;
   }
   return 0;
}