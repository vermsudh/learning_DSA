#include<iostream>
#include<vector>
using namespace std;
 
int digonalSum(int matrix[3][3], int n){ // O(n ^ 2)
    int PD, SD;
    int sum = 0;

    //PD : j == i;
    //SD : j = n - i -1;
    //We do not need a second loop to calculate the diagonal sum. 


    int diagonalSum;
    for(int i = 0; i<n; i++){
        sum+= matrix[i][i];
        if(i != n - i - 1){
            sum += matrix[i][n - i - 1];
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