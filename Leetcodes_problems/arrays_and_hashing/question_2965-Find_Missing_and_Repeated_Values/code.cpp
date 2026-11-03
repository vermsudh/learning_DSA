#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    
    vector<int> ans;
    int repeated, missing;

    int expSum = 0, actualSum = 0;

    //Lets find the repeating values which is 9 using sets. 

    unordered_set<int> set;
    int n = grid.size();
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(set.find(grid[i][j]) != set.end()){

                actualSum += grid[i][j];

                repeated = grid[i][j];
                ans.push_back(repeated);
            }
            set.insert(grid[i][j]);
        }

        expSum = (n*n) * (n * n + 1)/2;
        missing = expSum + repeated - actualSum;
        ans.push_back(missing);
    }
    return ans;
}
 
int main()
{

    vector<vector<int>> grid = {{9,1,7},
                                {8,9,2},
                                {3,4,6}};

    vector<int> result = findMissingAndRepeatedValues(grid);
    
    for(int i : result){
        cout << i << " ";
    }
    
    return 0;
}