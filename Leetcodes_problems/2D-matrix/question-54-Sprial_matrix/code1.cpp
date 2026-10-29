#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>>& mat){
    
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