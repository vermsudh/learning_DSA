#include <iostream>
using namespace std;

//WAP to calculate and product of all numbers in an array.
void sumproductArray(int arr[], int size, int &sum,int &product){
    sum = 0; 
    product = 1;

    for(int i= 0; i < size; i++){
        sum += arr[i];
        product *= arr[i];
    }
}

//WAF to swap the max and min number of the array
void swapMaxMin(){
    
}

int main(){
    cout << "//WAP to calculate and product of all numbers in an array." << endl;
    int arr[] = { 2, 5, 6};
    int size = sizeof(arr)/ sizeof(arr[0]); 

    int sum = 0; 
    int product = 1;

    sumproductArray(arr, size, sum, product);

    cout << "----------------------------" << endl;

    cout << "Sum: " << sum << endl;
    cout << "Product: " << product << endl;

    cout << "----------------------------";

    return 0;
    
}