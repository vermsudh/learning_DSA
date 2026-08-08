#include <iostream>
using namespace std;

// WAP to conver decimal into binary
int calculate_binart(int num){

    //suppose num = 5 . Binary is 101
    // Firstly, we will find the remainder by using % operator
    // Then, we are going to use that remainder
    // We have to run a while loop until the num is less than 0
    int pow = 1, ans = 0; 

    while( num > 0){
        int remainder = num % 2; // first we will find the remainder
        num = num / 2; // Then we will need to divide the num by 2 which will give us 
                        // next num. In case of 5 / 2 = 2, therefore num will be 2 for next step
        ans += (remainder * pow); // Now, in order to get our ans
                                  // we are going to add our remainder * pow
                                  // 1st iteration : 1 * 1 = 1
                                  // 2nd iteration : 0 * 10 = 0
                                  // 3rd iteration : 1 8 100 = 100

                                  // THerefore ans = 100 + 0 + 1 = 101
        pow = pow * 10; // This will increase the power by 10 ,100 , 1000
       
    }// This will stop when the number becomes less than 0
    return ans;
}

int main(){
    cout << calculate_binart(5);
    return 0;
}