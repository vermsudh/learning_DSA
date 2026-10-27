#include<iostream>
#include<vector>
using namespace std;

 
int searchMatrix(vector<vector<int>> mat, int target){
    //We have this matrix where the rows are ascending orders and //columns are in ascending order. 
    //Since we know that the numbers in the matrix are sorted and incrementing, then we can think of 
    //applying Binary Search instead of doing linear search to reduce the time complexity. 

    //SO, we would have to do binary search on this question. 
    //we know that in this matrix the values at [0][0] index would be the smallest and 
    // we know that values at [m-1][n-1] will be the largest becasuse we have ascending order sorted 
    //vector. 
    //We will have a range from the smallest and the largest. The Target can lie in between these numbers

    //Lets write the variables where we have to do binary search. 
    
    int m = mat.size(), n = mat[0].size(); //m will give us the size of rows and n is number of cols. 
    int row = 0;
    int col = n - 1;

    while(col >= 0 && row < m){
        //We are going to assume that our top right corner is mid point which is mat[0][4].
        //From here we have to decide either we have to the left or bottom. 
        //WHY Top Left corner as mid? 
        //As there will two direction, where we would have to search if target does not exist on 
        //this index. We would can disregard this whole col if mid == target. 

        if(target == mat[row][col]){
            return true;
        }else if(target < mat[row][col]){//Now if the target is smaller than the mid. 
            col--;//where c is the col
        }else{
            row++; 
        }
    }
    return false;
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