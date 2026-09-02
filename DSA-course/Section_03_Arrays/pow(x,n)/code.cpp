#include<iostream>
using namespace std;


    double myPow(double x, int n) {
        long binaryForm = n;
        if(n < 0){
            x = 1/x;
            binaryForm = - binaryForm;
        }
        double ans = 1;
        while(binaryForm > 0){
            if(binaryForm % 2 == 1){
                ans *= x;
            }
            x *= x;
            binaryForm /= 2;
        }
        return ans;
    }

int main()
{       
    double x;
    int n;
    cout << "Type the value of x : and n: " << endl;
    cin  >> x;
    cin >> n;
    cout << myPow(x, n);
    return 0;
}

// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
// Example 1:

// Input: x = 2.00000, n = 10
// Output: 1024.00000
// Example 2:

// Input: x = 2.10000, n = 3
// Output: 9.26100
// Example 3:

// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

// Constraints:

// -100.0 < x < 100.0
// -231 <= n <= 231-1
// n is an integer.
// Either x is not zero or n > 0.
// -104 <= xn <= 104

    double myPow(int x, int y){
        long binaryNum = y;
        double ans = 1;

        if(y < 0){
            x = 1/x;
            binaryNum = - binaryNum;
        }

        while(binaryNum > 0){
            if(binaryNum % 2 == 1){
                ans *= x;
            }
            x *= x;
            x /=2;
        }
    }