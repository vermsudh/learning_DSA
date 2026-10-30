#include <iostream>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
    //lets sort the array first. 
    sort(nums.begin(), nums.end());
    vector<int>ans;

    //Then we will run 2 pointers over the vector and find out the pairs. 
    int start = 0, end = nums.size();
    while(start < end){
        if(nums[start] + nums[end] > target){
            end--;
        }else if(nums[start] + nums[end] < target){
            start++;
        }
        else{
            ans.push_back(start);
            ans.push_back(end);
            return ans;
        }
    }
}

int main(){

    vector<int> nums = {2,7,11,15};
    int target = 9;

    cout << twoSum << endl;

    // We can first sort this array
    // Then we take first and the last element and add them
    // If it is going to be equal to target, then we will have the solution. 
    // we would know that we have taken a number which is larger than the target.
    // If not, then we would have to shift to previous smaller number. 
}
