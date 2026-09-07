#include<iostream>
#include<vector>
using namespace std;
 
int main()
{
    vector <int> nums = {0,1,0,3,12};

    int n = nums.size();
    int count = 0;

    //brute force (nested loop)
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n; j++){
            if(nums[i] == 0){
                swap(nums[i], nums[j]);
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }

    return 0;
}