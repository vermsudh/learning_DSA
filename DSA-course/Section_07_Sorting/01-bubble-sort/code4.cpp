#include<iostream>
#include<vector>
using namespace std;

// bubble sort is bascially checking the adjacent numbers and comparing them. 
// if one number is smaller than the other, then it moves to left side. 
// We can use nested for loops to solve 


void bubbleSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        bool isSwap = false;
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        if(isSwap == false){
            return;
        }
    }
}

int main()
{
    int n = 5;
    int arr[] = {4, 1, 5, 2, 3};

    cout << "Before sort : ";

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    bubbleSort(arr,n);

    cout << " After sort : " ;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}