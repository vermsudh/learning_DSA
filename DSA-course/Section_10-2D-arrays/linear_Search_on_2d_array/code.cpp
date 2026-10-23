#include<iostream>
#include<vector>
using namespace std;

//write a function that do a linear search over this matrix to check if 2 exists or not. 
string linearSearch(int matrix[4][3], int x){

    int rows = 4;
    int cols = 3;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(matrix[i][j] == x){
                return "It exists";
            }
        }
    }
    return "It does not exists";
}

pair<int, int> p1(int matrix[4][3], int x){
    int rows = 4;
    int cols = 3;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(matrix[i][j] == x){
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

int main()
{
    //normal array initlization and its values. 
    int arr[5] = {1, 2, 3, 4, 5};

    // we treat rows as normal array initlization. 
    int matrix[4][3] = {{1, 2, 3} , {4, 5, 6 }, {7, 8, 9}, {10, 11, 12}};
    int rows = 4;
    int cols = 3;
    
    int x = 2;

    cout << linearSearch(matrix, x) << endl;
    // return the pair of row and col when you find the keys. 

    auto pair = p1(matrix, x);
    
    cout <<"Position of x in the matrix is : "<< pair.first  << " " <<  pair.second << endl;

    return 0;
}