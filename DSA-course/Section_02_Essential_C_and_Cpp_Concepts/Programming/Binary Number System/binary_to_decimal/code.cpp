#include <iostream>
using namespace std;

// WAP to conver the binary number into decimal.

int calculateDecimal(int num){
    int ans = 0;
    int remainder;
    int power = 1;

    while(num > 0){

        remainder = num % 10;
        ans += (remainder * power);
        num /= 10;
        power *= 2;
    }
    return ans;
}

int main(){

    cout << calculateDecimal(101010);
    return 0;

}