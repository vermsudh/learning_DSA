#include <iostream>
using namespace std;

int sumOfDigits(int num){
    
    int sum = 0;
    while (num != 0){
        int last_digit = num % 10;
        sum = sum + last_digit;
        num = num / 10;
    }
    return sum;

}

int main(){

    cout << sumOfDigits(145);

    return 0;
}