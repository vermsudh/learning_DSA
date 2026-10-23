#include<iostream>
#include<vector>
using namespace std;

int gcd(int a, int b){
    int gcd = 1;
    //edge cases 
    if(a == 0) gcd = b; // if a = 0, b = 12, then gcd => b, as 0 can be divided by any number
    
    if(b == 0) gcd = a; // if a = 12, b = 0, then gcd => a

    if(a == b) gcd = a; // if we need to find out the GCD of a = 12, b = 12. We can have same gcd
    
    for(int i = 1; i < min(a, b); i++){
        if(a % i == 0 && b % i == 0){
            gcd = i;
        }
    }
    return gcd;
}
 
int main()
{
    int a = 20, b = 28;

    cout << gcd(a, b) << endl;

    return 0;
}