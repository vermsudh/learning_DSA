#include<iostream>
#include<vector>
using namespace std;

 
int main()
{
    vector<int> height = {1,7,2,5,4,7,3,6};

    int n = height.size();
    int maxWater = 0;
    for(int i = 0; i < n; i++){
    
        for(int j = 1; j < n; j++){

            int width = j - i;
            int ht = min(height[j], height[i]);

            int area = ht * width;
            maxWater = max(maxWater, area);
        }    
    }
    cout << maxWater << endl;

    return 0;
}