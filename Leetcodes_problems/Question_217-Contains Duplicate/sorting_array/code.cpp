#include<iostream>
using namespace std;
#include <vector>

bool hasDuplicate() {
        vector <int> nums = {1,2,3,4,5,5};
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 1; i++){
            if(nums[i] == nums[i + 1]){
                return true;
            }
        }
        return false;
    }

int main()
{   
    vector <int> nums = {1,2,3,4,5,5};

    hasDuplicate();

    return 0;
}