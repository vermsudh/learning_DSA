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
    int arr[5] = {5, 2, 9, 1, 7};

    cout << "The original array is : ";

    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;


    int max = INT_MIN;
    int min = INT_MAX;

    int max_index, min_index;

    for(int i = 0; i < 5; i++){
        if(max < arr[i]){
            max = arr[i];
            max_index = i;
        }
        if(min > arr[i]){
            min = arr[i];
            min_index = i;
        }
    }

    swap(arr[max_index], arr[min_index]);
    cout << "The swapped arr of max and min is : ";

    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
}

//WAF to print the unique values in the array.
int findUniqueValue(){
    int arr[] = {2, 4, 6, 6, 4 , 2, 9};

    for(int i = 0; i < 7; i++){
        cout << arr[i] <<" ";
    }

    cout << endl;
    //using brute force
    for(int i = 0; i < 7; i++ ){
        int count = 0;
        for(int j = 0; j < 7; j++){
            if(arr[i] == arr[j] ){
            count += 1;
            }
        }
        if(count == 1){
            cout << "The unique value in this array is : " << arr[i];
        }
    }
    return -1;
}

//WAF to print the intersection of a given array.

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
    cout << endl;

    swapMaxMin();

    cout << endl;

    cout << "----------------------------";

    cout << endl;

    findUniqueValue();

    cout << endl;

    cout << "----------------------------";

    return 0;
    
}