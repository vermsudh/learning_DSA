#include<iostream>
#include<vector>
using namespace std;

int digonalSum(int matrix[4][4], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){// primary diagonal where i = j (0,0), (1,1,) (2,2), (3,3);
                sum+= matrix[i][j];
            }else if(j == n - i - 1){// Secondary Digonal where (0, 3) (1, 2) (2,1) 
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

int digonalSum1(int matrix[4][4], int n){
    int sum = 0;
    //more Optamized approach where we do not have to define j as we know that PD: i= j, SD : j = n - i - 1

    for(int i = 0; i < n; i++){
        sum+= matrix[i][i];
        if(i != n - i - 1){
            sum += matrix[i][n - i -1];
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