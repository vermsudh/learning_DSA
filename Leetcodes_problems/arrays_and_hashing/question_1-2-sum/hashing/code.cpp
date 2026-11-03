#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
 
vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int, int> m; // key: number, value: index
    for(int i = 0; i < nums.size(); i++){
        int complement = target - nums[i]; // Find the required number
        
        // Check if complement already exists in map
        if(m.find(complement) != m.end()){
            return {m[complement], i}; // Return indices
        }
        
        // Store current number and its index
        m[nums[i]] = i;
    }
    return {}; // Return empty if no pair found
}

int main() {
    vector<int> nums = {2, 7, 11, 15, 17};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    
    // Print the result
    if(!result.empty()) {
        cout << "Indices: " << result[0] << " " << result[1] << endl;
    } else {
        cout << "No pair found." << endl;
    }
    
    return 0;
}