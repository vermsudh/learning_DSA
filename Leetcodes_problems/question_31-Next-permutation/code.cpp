#include<iostream>
#include<vector>
using namespace std;
 
void nextpermutation(vector<int>& nums){
    //1) 
}

int main()
{

    vector<int> nums = {1 , 2, 3, 6, 5, 4};
    // {1, 2, 4, 3, }

    nextpermutation(nums);

    for(int n : nums){
        cout << n << " ";
    }
    return 0;
}