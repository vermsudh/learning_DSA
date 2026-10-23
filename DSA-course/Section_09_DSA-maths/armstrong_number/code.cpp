#include<iostream>
#include<vector>
using namespace std;
 
bool isArmstrong(int n){
    int copyOfn = n;
    int sumOfCubes = 0; 

    while(n != 0){
        int dig = n % 10;
        sumOfCubes += (dig * dig * dig);
        n = n / 10;
    }

    return sumOfCubes == copyOfn;
}

int main()
{
    int n = 153;

    if(isArmstrong(n)){
        cout << "The num is armstrong number," ;
    }
    else{
        cout << "The num is not an armstrong number," ;
    }
    return 0;
}