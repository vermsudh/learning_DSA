#include<iostream>
using namespace std;
#include <vector>

int majElement(vector<int> nums) {

    int n = nums.size();
    int threshold = n / 2;

    for (int i = 0; i < n; i++) {

        int count = 1;

        for (int j = i + 1; j < n; j++) {

            if (nums[i] == nums[j]) {
                count++;
            }

            if (count > threshold) {
                return nums[i];
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {2,2,1,1,1,2,2};
    int result = majElement(nums);
    
    cout << "Maximum Element is : "<< result;
    return 0;
}