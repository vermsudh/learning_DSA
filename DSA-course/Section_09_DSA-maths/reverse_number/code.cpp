#include<iostream>
#include<vector>
using namespace std;
 
int reveseNum(int n){
    int revNum = 0;

    while(n != 0){
        int digit = n % 10;

        revNum = revNum * 10 + digit;

        n = n / 10;
    }
    return revNum;
}


int main()
{
    int n;
    cin >> n;

    cout << "The revese num of n is : " << reveseNum(n) << endl;

    return 0;
}