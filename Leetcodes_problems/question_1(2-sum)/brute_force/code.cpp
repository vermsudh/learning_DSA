#include <iostream>
using namespace std;

int main(){

    int nums[] = {2,7,11,15,17};
    int target = 9;
    int first_element, second_element, sum;
    for(int i = 0; i <= 5; i++){

        first_element = nums[i];

        for(int j = i + 1; j <= 5; j++){
            second_element = nums[j];
            sum = first_element + second_element;
            if(sum == target){
                cout << i, j;
            }
        }
    }
    return 0;
}
// Time complexity will be N ^ 2 as the loop is running twice.
// Space complexity will be 

// Why it is O(1)No Extra Data Structures: 
// The algorithm does not allocate any dynamic 
// memory or use structures like hash maps, 
// arrays, or trees to store data.Fixed Variables: 

// It only requires a few local variables to manage loop counters 
// (such as i and j) and to store temporary indices.Input-Independent: 
// The memory used remains identical whether the input array contains 5 elements or 5 million elements