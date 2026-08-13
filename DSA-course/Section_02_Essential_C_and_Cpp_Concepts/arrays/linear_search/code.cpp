#include <iostream>
using namespace std;

//WAP that can take the numbers from the user and store those number in the array. 
//Then prompt the user what number they would like to find in the array to check through an array.


int linearSearch(){

    int target = 56;

    const int MAX_SIZE = 100;
    int size;
    int arr[MAX_SIZE];

    cout << "Please type the numbers of elements you would like to have in this array : ";
    cin >> size;

    for(int i = 0; i < size; i++){
        cout << "Enter the value of index " << i << " in this array : ";
        cin >> arr[i];
    }

    for(int i = 0; i < size; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){


    // Linear Search to find a target value. 

    // Example: User type 16 , 56, 98, 78, 65 in the array and we need to find the number 56.

    int target = 56;
    linearSearch();

    return 0;
}