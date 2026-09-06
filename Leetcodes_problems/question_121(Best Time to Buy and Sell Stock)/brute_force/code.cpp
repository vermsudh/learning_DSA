#include<iostream>
#include<vector>
using namespace std;
 
int main()
{
    vector <int> prices = {7,1,5,3,6,4};

    int n = prices.size();
    int maxProfit = 0;

    for(int i = 0; i < n; i++){
        for(int j = 1 ; j < n; j++){
            int buy = prices[i];
            int sell = prices [j];
            int profit = sell - buy;
            maxProfit = max(maxProfit, profit);
        }
    }
    cout << maxProfit;

    return 0;
}