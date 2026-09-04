#include<iostream>
#include<vector>
#include <set>
using namespace std;
 
bool main()
{
    vector<int> nums = {1, 2, 3, 3};

    int n = nums.size();

    set<int> seen; 

    for(int i = 0; i < n; i++){
        seen.insert(nums[i]);
    }
    if(seen.size() == n){
        return false;
    }
    
    return true;
}