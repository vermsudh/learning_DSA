#include<iostream>
using namespace std;
#include <vector>

int main()
{
    vector<int> nums = {3, -4, 5, 4, -1, 7, -8};


    int max_sum = INT_MIN;
    // brute force
    for(int st = 0; st< nums.size(); st++){
        int vec_sum = 0;
        for(int end = st; end < nums.size(); end ++){
            vec_sum += nums[end];
            max_sum = max(vec_sum, max_sum);
        }
    }
    cout << max_sum;
    
    return 0;
}