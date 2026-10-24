#include<iostream>
#include<vector>
using namespace std;
 
int main()
{

    vector<vector<int>> mat = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat.size(); j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[i].size(); j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    //we can store more elements in 2D arrays as they are dynamic in size. 

    vector<vector<int>> mat1 = {
        {1,2,3},
        {4,5,6, 7, 8, 9},
        {7,8,9}
    };

    cout << endl;
    for(int i = 0; i < mat1.size(); i++){
        for(int j = 0; j < mat1[i].size(); j++){
            cout << mat1[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}