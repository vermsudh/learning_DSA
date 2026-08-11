#include <iostream>
using namespace std;

int main(){
  int n;
  cout << "Type the value of n : ";
  cin >> n; 

  for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
        cout << " "; // This inner loop will print the empty spaces.
        }
        for(int j = 0; j < n - i; j++)   {
        cout << i + 1 << " "; // this second inner loop will print the num;
        }
    cout << endl;
  }
  return 0;
}