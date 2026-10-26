#include<iostream>
#include<vector>
using namespace std;
 
int digonalSum(int matrix[3][3], int n){ // O(n ^ 2)
    int PD, SD;
    int sum = 0;
    
    int diagonalSum;
    for(int i = 0; i<n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                sum += matrix[i][j]; // PD
            }else if(j == n - i - 1){
                sum += matrix[i][j];// SD
            }
        }
    }
    return sum;
}  

int main()
{

    int matrix[3][3] = {{1, 2, 3} , {4, 5, 6 }, {7, 8, 9}};

    int n = 3;

    cout << digonalSum(matrix, n) << endl;

    return 0;
}