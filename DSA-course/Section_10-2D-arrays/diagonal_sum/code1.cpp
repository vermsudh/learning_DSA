#include<iostream>
#include<vector>
using namespace std;

int digonalSum(int matrix[4][4], int n){

    //we need a sum of diagonals. 
    // Primary Diagonal : 1 + 6 + 11 + 16
    //Secondary Diagonal : 4 + 7 + 10 + 13
    //Sum = 34 + 34 = > 68

    //PD : {i, j} = {0,0}, {1,1}, {2,2}, {3,3}
    //SD : {i, j} = {0,3}, {1,2}, {2,1}, {3, 0}
    //We notice that i and j remain equal to access the PD elements and 
    // for SD elements : i++ and j--.
    //for SD = i == j
    //for PD : i = 0; i++, j = n - i - 1 where n is the size of the matrix. 
    int sum = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0 ; j < n; j++){
            if(i == j){
                sum += matrix[i][j]; // PD
            }else if(j == n - i - 1){
                sum += matrix[i][j];// SD
            }
        }
    }
    cout << endl;
    return sum;
}

int digonalSum1(int matrix[4][4], int n){
    int sum = 0;
    //we know that PD : i == j and SD : j = n - i - 1
    for(int i = 0; i < n; i++){
        sum += matrix[i][i];
        if(i != n - i - 1){
            sum += matrix[i][n - i - 1];
        }
    }
    return sum;
}
 
int main()
{
    int matrix[4][4] = {{1, 2, 3, 4} , 
                        {5, 6, 7, 8}, 
                        {9, 10, 11, 12}, 
                        {13, 14, 15, 16}
                    };

    int n = 4;

    cout << digonalSum(matrix, 4) << endl;

    cout << digonalSum1(matrix, 4) << endl;


    return 0;
}