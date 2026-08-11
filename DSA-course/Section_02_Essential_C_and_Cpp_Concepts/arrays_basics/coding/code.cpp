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

    for(int i = 0; i <= 5; i++){
        cout << B[i] << " ";
    }
    //How to write for each loop? 





    
    return 0; // Please make sure you type everything before this return statment. 
                // If you type anything after return 0, the compliler will ignore it. 
}