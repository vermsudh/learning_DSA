#include<iostream>
#include<vector>
#include <unordered_set>

using namespace std;

int findDuplicate(vector<int>& nums) {

    unordered_set<int> s;
    int n = nums.size();

    for(int i = 0; i < n; i++){
        if(s.find(nums[i]) != s.end()){
            return nums[i];
        }
        s.insert(nums[i]);
    }
    return -1;
}
 
int main()
{

    vector<int> nums = {1, 3, 4, 2, 2};

    cout << findDuplicate(nums);

    return 0;
}