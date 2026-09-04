#include<iostream>
using namespace std;
#include <vector>

bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; i < n; j++){
                if(nums[i] == nums[j]){
                    return true;
                }
            }
        }
    }

int main()
{   
    vector <int> nums = {1,2,3,4};

    hasDuplicate(nums);

    return 0;
}