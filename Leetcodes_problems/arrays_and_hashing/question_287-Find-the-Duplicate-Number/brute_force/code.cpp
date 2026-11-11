#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int n = nums.size();

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(nums[i] == nums[j]){
                return nums[i];
            }
        }
    }
    return -1;
}
 
int main()
{

    vector<int> nums = {1, 3, 4, 2, 2};

    cout << findDuplicate(nums);

    return 0;
}