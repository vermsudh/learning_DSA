#include<iostream>
#include<vector>
using namespace std;
 
int main()
{
    vector <int> nums = {2,0,2,1,1,0};

    int count_0 = 0, count_1 = 0, count_2 = 0;;

    for(int i = 0; i < nums.size(); i++){
        //we can count 0, 1 and 2
        if(nums[i] == 0) count_0 += 1;
        if(nums[i] == 1)count_1 += 1;
        if(nums[i] == 2)count_2 +=1;
        
    }
    // vector<int> myVec(count, value);
    vector<int> sortedVec;

    sortedVec.assign(count_0, 0);
    sortedVec.insert(sortedVec.end(), count_1, 1);
    sortedVec.insert(sortedVec.end(), count_2, 2);

    for(int n : sortedVec){
        cout << n << " "; 
    }

    return 0;
}