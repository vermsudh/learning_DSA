#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>> mat, int target){
    
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