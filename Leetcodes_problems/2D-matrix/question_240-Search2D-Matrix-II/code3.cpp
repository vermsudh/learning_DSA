#include<iostream>
#include<vector>
using namespace std;

int searchMatrix(vector<vector<int>> mat, int target){
    //lets find the top left corner. 
        int rows = mat.size(), cols = mat[0].size();

        int row = 0, col = cols - 1;//4

        while(row < rows && col >= 0){
            //mat[row][col] is already assumed mid. 
            int mid = mat[row][col];
            if(target == mid){
                return true;
            }else if(target  < mid){
                col--;
            }else{
                row++;
            }

        }
    return false; 
}

int searchMatrix(vector<vector<int>> mat, int target){
    int rows = mat.size();
    int cols = mat[0].size();

    int row = rows; // 0
    int col = cols - 1; // 4

    while(col >= 0 && row < rows){ // row is 0 at first and rows are constatant which is 5 as rows = mat.size();
        int mid = mat[row][col];
        if(target == mid){
            return true;
        }else if(target < mid){
            col --;
        }else{
            row++;
        }
    }
}

int main()
{
    vector<vector<int>> mat = {{1,4,7,11,15},
                              {2,5,8,12,19}, 
                              {3,6,9,16,22},
                              {10,13,14,17,24},
                              {18,21,23,26,30}};
    int target = 5;

    cout << searchMatrix(mat, target);

    return 0;
}