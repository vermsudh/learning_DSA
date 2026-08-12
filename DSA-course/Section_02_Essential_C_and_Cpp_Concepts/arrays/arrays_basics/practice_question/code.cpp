#include <iostream>
using namespace std;

int main(){

    // Lets take the input from the user to store the values in the array. 

    int n, value;
    cout << "Enter the how many values you would like to store: ";
    cin >> n;

    int arr[n];
    
    for(int i = 0; i < n; i++){
        cout << "Enter the values now for " << i << endl;
        cin >> value;
        arr[i] = {value};
    }
    for(int val : arr){
        cout << val << " " << endl;
    }

    // Part 2 would be to find out the smallest and the largest numbers in the array. 
    //Lets divide the problem.

    int max = arr[0];
    int min = arr[0];
    // We can also do one more thing
    // we can initilize a variable called int smallest = INT_MAX

    int smallest = INT_MAX;
    for(int i = 0; i <= n - 1; i++){
        if(arr[i] < smallest){
            smallest = arr[i];
        }
    }
    cout << "THe smallest number in this array is : " << smallest;

    for(int i = 0; i <= n-1; i++){
       if(max < arr[i]){
            max = arr[i];
       }
    }
    cout << "The maximum element in this array is : " << max;
    
    // One more question we need to find the index value in the array which is the largest and the smallest. This is homework. 

    return 0;
}   