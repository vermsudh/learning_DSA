#include<iostream>
#include<vector>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    //Brute force approach of this question. 

    //We have to return the count of all the sub arrays where sum is equal to k. 
    //For this array : {2,-1,1,2}; 
    //sub arrays of this array will be {2} {-1} {1} {2}, {2, -1}, {-1, 1} {1, 2}, {2, -1, 1}{-1, 1, 2}, {2,-1,1,2}
    // 1st) {2}
    // 2nd {2, -1, 1}
    // 3rd {-1, 1, 2}
    // 4th {2}

// when i =0, j = 0
// i = 0 j = 2
// i = 1. j = 3
// i = 3, j = 3
    int n = nums.size(), count = 0;
    
    for(int i = 0; i < n; i++){
        int currentSum = 0; 
        for(int j = i; j < n; j++){
            currentSum += nums[j];
            
            if(currentSum == k){
                cout << " Value of i : " <<  i << " " << endl;
                cout << " Value of j : "<< j << " " << endl;
                count ++;
                
            }
        }
    }
    return count;
}
 
int main()
{

    vector<int> nums = {2,-1,1,2};
    int k = 2;

    cout << subarraySum(nums, k);

    return 0;
}