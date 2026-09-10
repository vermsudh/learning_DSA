#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target) {;
        int start = 0, end = nums.size() - 1;
        
        while(start <= end){
            
            int mid = start + (end - start)/2;

            if(nums[mid] == target){
                return mid;
            }// this is to know when we found our answer, then we would have to return that index

            if(nums[start] <= nums[mid]){
                if(nums[start] <= target && target <= nums[mid]){
                    end = mid - 1;
                }
                else{
                    start = mid +1;
                }
            }else{
                if(nums[mid] <= target && target <= nums[end]){
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            }
        }
        return -1;
    }

int main()
{
    vector <int> nums = {1,3};
    int target = 3;

    cout << search(nums, target) << endl; 

    return 0;
}