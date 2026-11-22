#include<iostream>
#include<vector>
using namespace std;

bool checkMid(vector<int> stalls, int c, int minAllowedDistance){

    int cowsCount = 1, lastStallPossible = 0;
    
    for(int i = 0; i < stalls.size() - 1; i++){
        if(stalls[i] - lastStallPossible <= minAllowedDistance){
            cowsCount ++;
            lastStallPossible = stalls[i];
        }
        if(cowsCount == c){
            return true;
        }
    }
    return false;
}

int aggresiveCows(vector<int> stalls, int c){

    int smallestValue = INT_MAX, largestValue = INT_MIN, ans = -1;
    sort(stalls.begin(), stalls.end());
    int start = 1, end = (stalls.size() - 1) - stalls[0];

    while(start <= end){
        int mid = start + (end - start)/2;

        if(checkMid(stalls, c, mid)){
            ans = mid;
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> stalls = {1, 2, 4, 8, 9 };
    int m = 3;
    cout << aggresiveCows(stalls, m) << endl;
    return 0;
}