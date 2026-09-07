#include<iostream>
#include<vector>
using namespace std;
 
int binarySearch(vector<int> nums, int target){
    int n = nums.size();
    int start = 0;
    int end = n -1;
    
    while (start <= end){
        int mid = (start+end)/ 2;

        if(nums[mid] == target){
            cout << "The number: " << nums[mid] << endl;
            cout << "The index value of it would be : ";
            return mid;
        }
        else if(nums[mid] < target){
            start = mid +1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}


int main()
{
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12};
    int target = 12;
    cout << binarySearch(arr1, target) << endl;

    return 0;
}