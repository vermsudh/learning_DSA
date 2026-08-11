#include <iostream>
using namespace std;

int main(){
    
    int A[5];
    A[0] = 12;
    A[1] = 23;
    A[2] = 34;

    cout << sizeof(A) << endl;
    cout << A[1];
    printf("%d\n", A[2]); // you can use C syntax in cpp.
    
    int B[6] = {3,4,5,6,4,3};

    // for(int i = 0; i <= 5; i++){
    //     cout << B[i] << " ";
    // }
    //How to write for each loop? 

    for(int x : B){
        cout << x << " ";
    }


    // Can we define the size of the array by taking an input from the user? 
    // Yes

    // Qyestion : WAP to take a input from the user to define the size of the array. 
    int n;
    cout << "Enter the value of n ? ";
    cin >> n;

    int C[n]; // You can take the input from the user for defining the size of the array but you wont be able to 
        // initlize the the values of the array. 

    // You would have print mention the the value either one by one or run a loop to take the valye of the user.
    int input;
    for(int i = 0; i <= n; i++){
        cout << "Enter the value of this inidce : " << endl;
        cin >> input;
        cout << "The value of " << i << " is : " << input;
    }
    for (int element : C) {
        std::cout << element << " ";
    }

    return 0; // Please make sure you type everything before this return statment. 
                // If you type anything after return 0, the compliler will ignore it. 
}