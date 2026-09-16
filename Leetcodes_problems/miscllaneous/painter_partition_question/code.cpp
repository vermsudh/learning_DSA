#include<iostream>
#include<vector>
using namespace std;

bool checkMid(vector<int> nums, int m, int mid){
    int board = 0;
    int numPainter = 1;

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > mid){
            return false;
        }
        if(nums[i] + board <= mid){
            board += nums[i];
        }else{
            numPainter++;
            board = nums[i];
        }
    }
    if(numPainter <= m){
        return true;
    }
    return false;
}
int paintPartition(vector<int> nums, int m){
    int start  = 0, sum = 0, ans = -1;
    for(int i = 0; i < nums.size(); i++){sum += nums[i];}
    int end = sum;
    while(start <=end){
        int mid = start + (end- start)/ 2;
        if(checkMid(nums, m, mid) == true){
            ans = mid;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {10, 10, 10, 10};
    vector<int> nums2 = {40, 30, 10, 20};
    int m = 2;
    cout << paintPartition(nums, m) << endl;
    cout << paintPartition(nums2, m);

    return 0;
}