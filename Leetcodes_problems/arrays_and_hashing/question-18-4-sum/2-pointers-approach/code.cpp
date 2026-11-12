#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;

    int n = nums.size();

    //Since we are using 2 pointers approach, we would need to sort the array. 
    sort(nums.begin(), nums.end());// TC : O(n log n)

    for(int i = 0; i < n; i++){
        //We have the first value. 

        if(i > 0 && nums[i] == nums[i - 1]) continue;

        for(int j = i + 1;j < n;){
            //We our values nums[i] ans nums[j] which will increment once we are done with the inner
            //loop of the 2 pointers approach. 

            int p = j + 1, q = n -1; //2 pointers. 

            while(p < q){

                long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[p] + 
                                (long long)nums[q];

                //Three conditions. We will find our quads when the sum of those will be equal to the 
                //target;        
                
                if(sum > target){
                    q--;
                }
                else if (sum < target){
                    p++;
                }
                else{
                    ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                    q--; p++;

                    //We have to make sure that we do not repeat the values. 
                    while(p < q && nums[p] == nums[p - 1]) p++;
                }
            }
            j++;
            //We have to make sure that we do not repeat the values of j as well. 

            while(j < n && nums[j] == nums[j - 1]) j++;
        }
    }
    return ans;
}

int main()
{

    vector<int> nums = {3,2,3,-3,1,0};
    int target = 3;

    //Output: [[-3,0,3,3],[-3,1,2,3]]

    vector<vector<int>> result = fourSum(nums, target);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n"; // Prints each triplet on a new line
    }
    
    return 0;
}