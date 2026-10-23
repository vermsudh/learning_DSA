#include<iostream>
#include<vector>
using namespace std;
 
int main()
{
    //normal array initlization and its values. 
    int arr[5] = {1, 2, 3, 4, 5};

    // we treat rows as normal array initlization. 
    int matrix[4][3] = {{1, 2, 3} , {4, 5, 6 }, {7, 8, 9}, {10, 11, 12}};
    int rows = 4;
    int cols = 3;
    
    //how to access any element? 
    //we would need to mention the row and col to get the right address of the value. 

    //Print 8 here. 

    cout << matrix[2][1] << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    //how to change the value in the matrix? 
    //we can simply access the element and change the value to 18. 

    //how to print the 2D arrays using nested for loop? 
    cout << "The matrix print is below." << endl;
    cout << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    // how to take inputs from the users to make a matrix? 
    
    int mat[3][3];
    
    int row_input = 3, col_input = 3; 

    cout << "Type the values of rows by rows." << endl;
    //input
    for(int i = 0; i < row_input; i++){
        for(int j = 0; j < col_input; j++){
            cin >> mat[i][j];
        }
    }
    //output
    for(int i = 0; i < row_input; i++){
        for(int j = 0; j < col_input; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
 

    return 0;
}