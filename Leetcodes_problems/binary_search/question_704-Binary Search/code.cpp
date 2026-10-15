#include<iostream>
#include<vector>
using namespace std;
 
int binarysearch(vector<int>& nums, int target) {

        int n = nums.size();

        int start = 0, end = n -1;

        while(start <= end){
            int mid = start + (end - start)/2;

            if(nums[mid] == target){
                return mid;
            }

            if(nums[mid] > target){
                end = mid - 1;
            }else{
                start = mid + 1;
            }

        }
        return -1;
    }

int main()
{
    return 0;
}