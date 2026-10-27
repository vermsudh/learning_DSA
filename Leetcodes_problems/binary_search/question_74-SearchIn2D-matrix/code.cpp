#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>> mat, int target){
    int rows = mat.size();
    int cols = mat[0].size();
    int start = 0, end = rows * cols - 1;

    while(start <= end){

        int mid = start + (end - start)/ 2; 
        int row = mid / cols;
        int col = mid % cols;

        if(mat[row][col] == target){
            return true;
        }else if(target > mat[row][col]){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return false;
}

int main()
{

    vector<vector<int>> mat = {{1, 3, 5, 7}
                            , {10,11,16,20}, 
                              {23,30,34,60}};
    int target = 34;

    cout << searchMatrix(mat, target);

    return 0;
}