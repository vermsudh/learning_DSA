#include<iostream>
using namespace std;
#include <vector>

// Kadane's Algorithm

int main()
{
    vector<int> nums = {3, -4, 5, 4, -1, 7, -8};

    int current_sum = 0;
    int max_sum = INT_MIN;
    // kadane's algorithm
    for(int value : nums){
        // This will add the values of the arrays 1) iteration  = 0 + 3 => 3
        current_sum += value;
        max_sum = max(max_sum, current_sum);

        if(current_sum < 0){
            current_sum = 0;
        }
    }

    cout << max_sum;

    
    return 0;
}