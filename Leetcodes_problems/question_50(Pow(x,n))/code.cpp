#include<iostream>
using namespace std;

double myPow(double x, int n) {
    long binaryForm;
    double ans = 1;

    if(n < 0){
        x = 1/x;
        binaryForm = - binaryForm;
    }

    while(binaryForm > 0){
        if(binaryForm % 2 == 1){
            ans *=x;
        }
        x *= x;
        binaryForm /= 2;
    }
    return ans;
}

int main()
{
    return 0;
}

