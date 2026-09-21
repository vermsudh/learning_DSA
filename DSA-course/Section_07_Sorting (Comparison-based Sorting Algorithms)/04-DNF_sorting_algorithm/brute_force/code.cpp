#include<iostream>
#include<vector>
using namespace std;
 
int main()
{
    vector <int> nums = {2,0,2,1,1,0};

    sort(nums.begin(), nums.end());
    //time complexity of this sort will be O(nlogn)
    //as we are using inbuilt sorting from c++ -  Introsort

    //Introsort. It begins with Quicksort, switches to Heapsort if the recursion depth exceeds 
    //a threshold (preventing worst-case degradation), and uses Insertion Sort for small subarrays.

    for(int i = 0; i < nums.size(); i++){
        cout << nums[i];
    }
    return 0;
}