#include<iostream>
#include<vector>
using namespace std;

bool checkMid(vector<int> stalls, int c, int mid){


}

int aggresiveCows(vector<int> stalls, int c){
    int smallestValue = INT_MAX, largestValue = INT_MIN, ans = -1;

    for(int i = 0; i < stalls.size(); i++){
        smallestValue = min(smallestValue, stalls[i]);
        largestValue = max(largestValue, stalls[i]);
    }
    int start = 1, end = largestValue - smallestValue;

    while(start <= end){
        int mid = start + (end - start)/2;
    }
}

int main()
{
    vector<int> stalls = {1, 2, 4, 8, 9 };
    int m = 3;
    cout << aggresiveCows(stalls, m) << endl;
    return 0;
}