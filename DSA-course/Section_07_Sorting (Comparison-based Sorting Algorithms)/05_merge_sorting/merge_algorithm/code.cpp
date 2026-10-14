#include<iostream>
#include<vector>
using namespace std;

// Added '&' to pass vectors by reference so modifications persist
void merge(vector<int>& nums1, vector<int>& nums2, int m, int n){
    int ind = m + n - 1,  i = m - 1, j = n - 1;

    while(i >= 0 && j >= 0){
        if(nums1[i] >= nums2[j]){
            nums1[ind] = nums1[i];
            ind--; i--;
        }else{
            nums1[ind] = nums2[j];
            ind--; j--;
        }
    }
    while(j >= 0){
        nums1[ind] = nums2[j];
        ind--;
        j--;
    }
}
 
int main()
{
    vector<int>nums1 = {4, 5, 6, 0, 0, 0};
    vector<int>nums2 = {1, 2, 3};

    // m is 3 (actual elements), n is 3 (elements to merge from nums2)
    merge(nums1, nums2, 3, 3);

    for(int n : nums1){
        cout << n << " ";
    }

    return 0;
}
