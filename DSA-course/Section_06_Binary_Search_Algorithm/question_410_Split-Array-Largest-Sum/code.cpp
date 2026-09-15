#include<iostream>
#include<vector>
using namespace std;

bool midCheck(vector<int> arr, int m, int mid){

    int n = arr.size();

    int students = 1;
    int pages = 0;

    for(int i = 0; i < n; i++){
        if(pages + arr[i] <= mid){
            pages += arr[i];
        }else{
            students ++;
            pages = arr[i];
        }
    }

    if(students <= m){
        return true;
    }
    return false;

}

int allocateBooks(vector<int> arr, int n, int m){
    int start = 0, sum = 0;

    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    int end  = sum;
    int ans = -1;

    while (start <= end){

        int mid = start + (end - start)/2;

        if(midCheck(arr, m, mid) == true){
            ans = mid;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return ans;
}
 
int main()
{
    // vector<int> arr = {2,1,3,4};
    vector<int> nums = {1,4,4};

    // cout << allocateBooks(arr, 4, 2) << endl;

    cout << allocateBooks(nums, 3, 3);

    return 0;
}