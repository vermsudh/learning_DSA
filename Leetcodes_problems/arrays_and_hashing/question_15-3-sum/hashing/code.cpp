#include<iostream>
#include<vector>
#include<set>
using namespace std;
 
vector<vector<int>> threeSum(vector<int>& nums) {
        //Brute force O(n^3 * log(unique_triplets))

        set<vector<int>> s;
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        vector<int> triplets = {nums[i], nums[j], nums[k]};

                        sort(triplets.begin(), triplets.end());

                        if(s.find(triplets) == s.end()){//since we are using sets instead of unordered_sets. 
                            //TC : O(log(triplets)) 
                            s.insert(triplets);
                            ans.push_back(triplets);
                        }
                    }
                }
            }
        }
        return ans;
    }

int main() {
   
    
    return 0;
}