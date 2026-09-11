#include<iostream>
#include<vector>
using namespace std;

void isValid(vector<int> arr, int n, int m, int maxAllowedPages){
    
}

int allocateBooks(vector<int> arr, int n, int m){

    int start = 0;
    int sum = 0;
    for(int i = 0; i < arr.size(); i++){
        sum += arr[i];
    }
    int end = sum;

    cout << end;

    // while(start <= end){
        
    // }

    return 0;
}
 
int main()
{
    vector<int> arr = {2,1,3,4};
    int n = 4, m = 2;

    cout << allocateBooks(arr, n, m) << endl;


    return 0;
}