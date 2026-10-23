#include<iostream>
#include<vector>
using namespace std;
 



    int reverseNum(int n){
        int revNum = 0;

        while(n != 0){
            int digit = n % 10;
            if(revNum > INT_MAX/10 || revNum < INT_MIN /10){
                return 0;
            }
            revNum = revNum * 10 + digit;
            n = n / 10;
        }
        return revNum;
    }

    bool isPalindrome(int n) {
        int reverseNumber = reverseNum(n);

        if(n == reverseNumber){
            return true;
        }else{
            return false;
        }
    }

int main()
{
    int n;
    cout << "type the value of n : ";
    cin >> n;

    cout << "This number is palindromic : (T/F) " << isPalindrome(n) << endl;

    return 0;
}