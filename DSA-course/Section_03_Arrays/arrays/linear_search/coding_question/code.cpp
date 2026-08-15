#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target){

    for(int i = 0; i < size; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

// Time complexity is O(n)

int main(){
    int arr[] = {56, 98, 78, 98, 65};
    int size = 5;
    int target = 98;

    int size = sizeof(arr)/ sizeof(arr[0]);
    cout << linearSearch(arr, size, target) << endl;

    return 0;
}