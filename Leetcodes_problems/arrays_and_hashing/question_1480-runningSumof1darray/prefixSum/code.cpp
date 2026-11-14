#include<iostream>
#include<vector>
using namespace std;
 
vector<int> runningSum(vector<int>& nums) {
        
        int prefixSum = 0; 
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i];
            ans.push_back(prefixSum);
        }
        return ans;
}

int main()
{

    vector<int> nums = {1,2,3,4};
    vector<int> result = runningSum(nums);

    for(int i : result){
        cout << i << " ";
    }

    return 0;
}