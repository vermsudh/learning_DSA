#include <iostream>
#include <vector>
using namespace std;
 
// Pass vector by reference (&) to avoid copying it in every recursive call
int binarySearch(const vector<int>& nums, int target, int start, int end) {
    
    // Base case: If the search space becomes invalid, the target is not found
    if (start > end) {
        return -1;
    }

    int mid = start + (end - start) / 2;
    
    if (nums[mid] == target) {
        return mid; // Target found
    }
    else if (nums[mid] < target) {
        // Search in the right half
        return binarySearch(nums, target, mid + 1, end);
    }
    else {
        // Search in the left half
        return binarySearch(nums, target, start, mid - 1);
    }
}

int main() {
    vector<int> nums = {-1, 0, 3, 4, 5, 9, 12};
    int target = 12;
    
    int n = nums.size(); 
    // You must pass the start and end indices when calling the function
    cout << binarySearch(nums, target, 0, n - 1) << endl;

    return 0;
}
