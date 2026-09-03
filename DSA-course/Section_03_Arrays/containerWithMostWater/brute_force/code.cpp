#include<iostream>
using namespace std;

int containerWithMostWater(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    //brute force
    int maxWater = 0;


    for(int left = 0; left < height.size(); left++){

        for(int right = left + 1; right < height.size();right++){
            int width = right - left;
            int height = min(left, right);
            int currentWater = width * height;

            maxWater = max(currentWater, maxWater);
        }
    }
    return maxWater;
}



int main()
{
    return 0;
}