#include<iostream>
#include<vector>
using namespace std;
 
int recursionGcd(int a, int b){
    if(b == 0) return a;

    return recursionGcd(b, a % b);
}
 
int lcm(int a, int b){
    int lcm = 1;

    int prod = a * b;

    lcm = prod / recursionGcd(a, b);
    
    return lcm;
}

int main()
{
    int a = 20, b = 28;

    cout << lcm(a, b) << endl;

    return 0;
}