#include<iostream>
using namespace std;
#include <vector>

//using sorting, this will bring the time complexity o(n)
// sorting takes o(n log n)
// time complexity will be O(nlogn)
int main()
{   
    vector <int> nums = {2,2,1,1,1,2,2};
    int n = nums.size();

    int ans = nums[0];

    sort(nums.begin(), nums.end());
    // sorted arrat = {1 1 1 2 2 2 2}
    for(int i = 0; i < n; i++){
        int count = 1;

        if(nums[i] == nums[i + 1]){
            count +=1;
            i++;
        }
        else{
            count = 1;
            int ans = nums[i];
        }
        if(count > n/2){
            return ans;
        }
    }

    return 0;
}

//Leetcode
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {

//         int n = nums.size();
//         //sort the array
//         sort(nums.begin(), nums.end());
//         int frequency = 1, ans = nums[0];
//         for(int i = 1; i < n; i++){
            

//             if(nums[i] == nums[i - 1]){
//                 frequency ++;
//             }else{
//                 frequency = 1;
//                 ans = nums[i];
//             }
//             if(frequency > n/2){
//                 return ans;
//             }
//         }
//         return ans;
//     }
// };