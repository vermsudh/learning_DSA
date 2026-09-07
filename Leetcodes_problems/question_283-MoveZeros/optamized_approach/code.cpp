#include<iostream>
#include<vector>
using namespace std;
 
int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    int n = nums.size();

    int left = 0;
    int right = 0;

    while(right < n){

        if(nums[right] != 0){
            swap(nums[right], nums[left]);
            left++;
        }
        right++;
    }

    for(int i = 0; i < n; i++){
        cout << nums[i];
    }

    return 0;
}