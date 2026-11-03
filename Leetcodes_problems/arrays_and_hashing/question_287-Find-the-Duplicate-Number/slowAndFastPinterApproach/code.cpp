#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int>& nums) {

    //We have to solve this question using slow and fast pointer approach. 

    //At first, we are going to initlize both the pointers with 0th index element. 
    int slow = nums[0], fast = nums[0];
    //1) At first, we are going to move the slow pointer with 1 step and fast pointer by 2. 
    
    do{

        slow = nums[slow];
        fast = nums[nums[fast]];

    }while(slow != fast);

    //initlize the slow with nums[0] again. 
    slow = nums[0];
    //2) Now, we are going to increment the slow with +1 and fast with + 1; 

    while(fast != slow){
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;

}
 
int main()
{

    vector<int> nums = {1, 3, 4, 2, 2};

    cout << findDuplicate(nums);

    return 0;
}