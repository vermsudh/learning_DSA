#include <iostream>
using namespace std;

int main(){
  int n;
  cout << "Type the value of n : ";
  cin >> n; 

  for(int i = 0; i < n; i++){
    // First we are going to print the spces which is going to run until n - i -1
    for(int j = 0; j < n - i - 1; j++){
        cout << " ";
    }   
    // Then we are going to the print the num1 pattern
    for(int j = 1; j <= i + 1; j++ ){
        cout << j;
    }
    for(int j = i; j > 0 ; j--){ //backwards loop which will run till j becomes less than or equal to 0. 
        cout << j;
    }
    cout << endl;
  }
  return 0;
}