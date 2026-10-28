#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>>& mat){
    vector<int> result;

    int m = mat.size(); // number of rows. 
    int n = mat[0].size(); // number of cols. 

    //Now would need 4 variables that will access the corners. 
    int srow = 0, scol = 0, erow = m - 1, ecol = n - 1;


    return result;
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