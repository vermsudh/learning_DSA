#include<iostream>
using namespace std;
#include <vector>

int main()
{
    vector <int> nums = {2, 2, 2, 2, 1, 1, 1, 2, 2, 2};
    int n = nums.size();

    for(int i : nums){
        int count = 1;
        for(int j : nums){
            if(i == j){
                count += 1;
            }
        }
        if(count > n/2){
            cout << "Majority Element is : " << i << endl;
            return 0;
        }
    }

    cout << "No Majority Element was found";
    return 0;
}

