#include<iostream>
#include<vector>
using namespace std;


vector<int> productExceptSelf(){

        vector <int> nums ={1,2,3,4};

        int n = nums.size();
        vector <int> ans(n,1);

        vector <int> suffix(n,1);
        vector <int> prefix(n,1);

        //prefix
        for(int i = 1; i < n; i++){
            prefix[0] = 1;
            prefix[i] = prefix[i - 1] * nums[i -1];
            cout << prefix[i] << endl;
        }
        //suffix
        for(int i = n - 2; i >= 0; i--){
            suffix[0] = 1;
            suffix[i] = suffix[i + 1] * nums [i + 1];
        }
        //ans -> suffix * prefix
        for(int i = 0; i < n; i++){
            ans[i] = suffix[i] * prefix[i];
        }
        return ans;
}

int main()
{
    vector <int> result = productExceptSelf();

    for(int x : result){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}




    

