#include<iostream>
#include<vector>
using namespace std;
 
int maxSumRow(int matrix[3][3], int row, int col){

    int rowSum = 0;
    int maxRowSum = INT_MIN;
    for(int i = 0; i < row; i++){
        rowSum = 0;
        for(int j = 0; j < col; j++){
            rowSum += matrix[i][j];
        }
        maxRowSum = max(rowSum, maxRowSum);
    }
    return maxRowSum;
}

int main()
{
    int matrix[3][3] = {{1, 2, 3} , {4, 5, 6 }, {7, 8, 9}};
    int rows = 3;
    int cols = 3;

    cout << "The maxium sum row is: " << maxSumRow(matrix, 3, 3);

    return 0;
}