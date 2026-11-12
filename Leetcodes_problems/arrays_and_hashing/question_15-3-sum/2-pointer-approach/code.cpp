#include <iostream>
#include <vector>
#include <algorithm> // Required for sort()
using namespace std;
 
vector<vector<int>> threeSum(vector<int>& nums) {
    // Sort the array first
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();

    // Traverse over the array
    for (int i = 0; i < n; i++) {
        // Skip duplicate values for the first element
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int j = i + 1, k = n - 1;

        // Fixed: j < k (was j > k)
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];

            if (sum > 0) {
                k--;
            } else if (sum < 0) {
                j++;
            } else {
                ans.push_back({nums[i], nums[j], nums[k]});
                k--; 
                j++;
                // Fixed: j < k (was j > k)
                while (j < k && nums[j] == nums[j - 1]) j++;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {2, -1, 4, -1, 0, 1};

    vector<vector<int>> result = threeSum(nums);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n"; // Prints each triplet on a new line
    }
    
    return 0;
}
