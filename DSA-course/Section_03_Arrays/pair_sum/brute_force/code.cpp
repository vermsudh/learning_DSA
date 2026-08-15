#include<iostream>
using namespace std;
#include <vector>

vector<int> pairSum(vector<int> nums, int target){
    vector<int> ans;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(nums[i] + nums[j] == target){
                ans.push_back(i);
                ans.push_back(i);
            }
            return ans;
        }
    }
    return ans;
}

int main()
{
    // Pair sum solution
    vector <int> nums = {2, 7, 11, 15};

    int target = 9;
    
    for(int value1 : nums){
            
        for(int value2 : nums){
            int sum = value1 + value2;
            if(sum == target){
                cout << "Pair found: " << value1 << " " << value2 << endl;
                return 0;
            }
        }
    }
    vector <int>ans = pairSum(nums, target);
    cout << ans[0] << " "<< ans[1] << endl;

    return 0;
}