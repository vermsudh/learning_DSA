#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    //Prefix Sum.

    //First would have to initlize the PS and count and store these two in the maps where 
    //PS is going to be key and the count will be value. 

    //We need a unordered_map as we need to do the operation in O(1). 
    unordered_map<int, int> m;

    int prefixSum = 0;//We will initlize this with 0 as currently the sum is nothing which is 0. 
    int count = 0; // Same for the counts as well. 

    //We would need to initlize the first value of map to be 0 as we need to tell the program to 
    //include the sum of of 0 index which is 2 if nums = {2,-1,1,2};
    
    m[0] = 1; //where m[key] = value. 
    //assigning the values in the map using Using the Subscript Operator []

    //Now, we need to travese over the vector nums. 

    for(int i = 0; i < nums.size(); i++){
        prefixSum += nums[i];
        int remove = prefixSum - k;//If we need to calculate the sum of current subarray like from idx 
        // from 0 to 2. 
        //Now we would need to store remove in the maps. 
        count += m[remove];// We will check if key is present or not, if it is then, we will increse the count or freq. 
        m[prefixSum]++;//This step is for storing the PS in the maps. 
        
    }

    return count; //We have to return the count. Count is nothing but sub arrays where the sum
    //of the elements is equal to k. which is 2. 
    
}
 
int main()
{

    vector<int> nums = {2,-1,1,2};
    int k = 2;

    cout << subarraySum(nums, k);

    return 0;
}