#include<iostream>
using namespace std;
#include <vector>


// We are going to use 2 pointer approach
//since it has been given the the vector has been sorted already.
// we would have to run a loop over the vector and take the start and end elements. 
// Then we are going to add them together and compare it target. If they are equal, then we return the 
// start and end pair. 
// If not, then we will increment the start with 1 and add it again to compare it if sum > target in the last iteration.
// we will keep doing this until we find out the sum == target.

vector<int> pairSum(vector<int> nums, int target){
    vector<int> ans;
    int n = nums.size();

    int start = 0, end = n-1;
    while(start < end){
        int pairSum = nums[start] + nums[end];
        if(pairSum > target){
            end --; 
        }
        else if(pairSum < target){
            start ++;
        }
        else{
            ans.push_back(start);
            ans.push_back(end);
            return ans;
        }
    }
}

int main()
{
    // Pair sum solution
    vector <int> nums = {2, 7, 11, 15};
    int target = 26;
    
    vector<int> ans = pairSum(nums, target);
    cout << ans[0] << ", " << ans[1] << endl;

    return 0;
}

