#include<iostream>
#include<vector>
using namespace std;
 
int digonalSum(int matrix[3][3], int rows, int cols){
    int PD, SD;
    int diagonalSum;
    for(int i = 0; i < rows;){
        for(int j = 0; j < cols; j++){
            PD = matrix[i][j];
        }
        i++;  
    }
}  

int main()
{

    int matrix[3][3] = {{1, 2, 3} , {4, 5, 6 }, {7, 8, 9}};

    int rows = 3;
    int cols = 3;

    cout << digonalSum(matrix, rows, cols) << endl;

    return 0;
}