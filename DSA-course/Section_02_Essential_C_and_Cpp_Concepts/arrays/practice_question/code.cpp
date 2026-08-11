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
        cout << val << " ";
    }

    // Part 2 would be to find out the smallest and the largest numbers in the array. 
    //Lets divide the problem.

    

    return 0;
}   