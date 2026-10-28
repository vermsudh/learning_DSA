#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>>& mat){
    vector<int> ans;

    int m = mat.size(); // number of rows. 
    int n = mat[0].size(); // number of cols. 

    //Now would need 4 variables that will access the corners. 
    int srow = 0, scol = 0, erow = m - 1, ecol = n - 1;

    while(srow <= erow && scol <= ecol){
        //Now, we have to write loops to iterate over top, right, bottom, and left sides.

        //print all the boundaries. 
        //top
        for(int i = scol; i <= ecol; i ++ ){
            ans.push_back(mat[srow][i]);
        }
        //right
        for(int j = srow + 1; j <= erow; j++){
            ans.push_back(mat[j][ecol]);
        }
        //bottom
        for(int i = ecol - 1; i >= scol; i--){
            if(srow == erow){
                break;
            }
            ans.push_back(mat[erow][i]);
        }
        //left
        for(int j = erow - 1; j >= srow + 1; j--){
            if(ecol == scol){
                break;
            }
            ans.push_back(mat[j][scol]);
        }
        srow++; scol++;
        erow--; ecol--;
    }
    return ans;
}
 
int main()
{
 
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12},
        {13,14,15,16}
    };

    vector<int> result = spiralMatrix(mat);

    for(int i : result){
        cout << i << " ";
    }

    return 0;
}