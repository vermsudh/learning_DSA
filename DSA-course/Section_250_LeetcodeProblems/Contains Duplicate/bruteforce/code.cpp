#include<iostream>
using namespace std;
#include <vector>

bool hasDuplicate(vector<int>& nums) {
    
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(nums[i] == nums[j]){
                    cout << "contains duplicate";
                    return true;
                }
            }
        }
        cout << "Does not contain duplicate";
        return false;
    }

int main()
{   
    vector <int> nums = {1,2,3,4,5, 5};

    hasDuplicate(nums);

    return 0;
}