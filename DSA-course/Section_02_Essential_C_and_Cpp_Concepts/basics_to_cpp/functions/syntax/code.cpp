#include <iostream>
using namespace std;

void myFunction(){
        cout << "This is my first function";
    }
int sum(int a, int b){
    int sum = a + b;
    return sum;
}
int minoftwo(int a, int b){ // paramaters
    if(a < b){
        cout << "a is min";
    }else{
        cout << "b is min";
    }
    return a, b;
}
int sumofn(int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum +=i;
    }
    cout << "The sum from 1 to n is : ";
    return sum;
}
int nfactorial(int n){
    int factorial = 1;
    for(int i = 1; i <= n; i ++){
        factorial *= i;
    }
    return factorial;
}
int main(){
    myFunction();
    // cout << sum(4,5);
    cout << endl;
    minoftwo(8, 9); //arguments
    cout << endl;
    cout << sumofn(2) << endl;
    cout << nfactorial(5) << endl;
    return 0;
}