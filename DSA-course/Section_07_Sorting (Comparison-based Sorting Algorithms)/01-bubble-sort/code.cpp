#include<iostream>
#include<vector>
using namespace std;

//brute force which will have time complexity as O(n^2)
void bubbleSort(int arr[], int n){ 
    for(int i = 0; i < n -1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

//more optmazied apprach in orde to stop the sorting once the sorting is completed.
void bubbleSortOptamized(int arr[], int n){ 
    for(int i = 0; i < n -1; i++){
        //optimization to make the loop stop when the array has been sorted. 
        bool isSwap = false;
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap){
            return;
        }
    }
}

// Start with the first pass: i = 0

// Nothing is sorted yet.

// [4, 1, 5, 2, 3]

// We need to compare:

// arr[0] with arr[1]
// arr[1] with arr[2]
// arr[2] with arr[3]
// arr[3] with arr[4]

// So j needs:

// 0, 1, 2, 3

// That's 4 comparisons.



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