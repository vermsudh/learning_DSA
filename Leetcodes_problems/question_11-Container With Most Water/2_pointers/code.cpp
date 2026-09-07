#include<iostream>
#include<vector>
using namespace std;
 
int main()
{   
    vector<int> height = {1,7,2,5,4,7,3,6};

    int n = height.size();

    int left = 0;
    int right = n-1;

    int maxWater = 0;


    while(right > left){
        int width = right - left;
        int ht = min(height[left], height[right]);

        int area = width * ht;
        maxWater = max(maxWater, area);

        if(height[left] < height[right]){
            left ++;
        }
        else{
            right --;
        }
    }
    cout << maxWater << endl;
    
    return 0;
}