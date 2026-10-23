#include<iostream>
#include<vector>
using namespace std;
 
int maxSumRow(int matrix[3][3], int row, int col){

    
    int maxColSum = INT_MIN;
    
    //We need the sum of mat [0,0] + [1,0] + [2,0] Then : [0,1] + [1,1] + [2,1], Then [0,2] + [1,2] + [2,2]
    for(int j =0; j < col; ++j){
        int colSum = 0;
        for(int i = 0; i < row; ++i){
            colSum += matrix[i][j];
        }
        maxColSum = max(maxColSum, colSum );
    }

    return maxColSum;
}

int main()
{
    int matrix[3][3] = {{1, 2, 3} , {4, 5, 6 }, {7, 8, 9}};
    int rows = 3;
    int cols = 3;

    cout << "The maxium sum col is: " << maxSumRow(matrix, 3, 3);

    return 0;
}