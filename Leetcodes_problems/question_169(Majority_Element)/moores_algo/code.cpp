#include<iostream>
using namespace std;
#include <vector>


int main()
{
    vector <int> nums = {2, 2, 2, 2, 1, 1, 1, 2, 2, 2};

    int frequency = 0, ans = 0;
    int n = nums.size();

    for(int i =0; i < n; i++){

        if(frequency == 0){
            ans = nums[i];
        }
        if(ans == nums[i]){
            frequency++;
        }
        else{
            frequency--;
        }
    }
    cout << ans;
    
    return ans;
}