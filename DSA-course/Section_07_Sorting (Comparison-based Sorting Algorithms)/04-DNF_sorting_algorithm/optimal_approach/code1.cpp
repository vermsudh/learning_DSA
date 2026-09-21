#include<iostream>
#include<vector>
using namespace std;

void sortColors(vector<int>& nums) {
        int count_0 = 0, count_1 = 0, count_2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) count_0++;
            if(nums[i] == 1) count_1++;
            if(nums[i] == 2) count_2++;
        }
        int index = 0;
        for(int i = 0; i < count_0; i++){
            nums[index++] = 0;
        }
        for(int i = 0; i < count_1; i++){
            nums[index++] = 1;
        }
        for(int i = 0; i < count_2; i++){
            nums[index++] = 2;
        }
}
 
int main()
{
    vector <int> nums = {2,0,2,1,1,0};
    cout << "Before Sort";

    for(int n :nums){
        cout << n << " ";
    }
    sortColors(nums);

    cout << endl << "After Sort ";

    for(int n :nums){
        cout << n << " ";
    }
    return 0;
}

