#include<iostream>
#include<vector>
using namespace std;

int gcd(int a, int b){

    while(a > 0 && b > 0){
        if(a > b){
            a = a % b;
        }else{
            b = b % a;
        }
    }
    if(a == 0 )return b;

    return a;
}

int recursionGcd(int a, int b){
    if(b == 0) return a;

    return recursionGcd(b, a % b);
}
 
int main()
{
    int a = 20, b = 28;

    cout << gcd(a, b) << endl;

    cout << recursionGcd(a, b) << endl;

    return 0;
}