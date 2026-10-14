#include<iostream>
#include<unordered_map>
using namespace std;
 
int main()
{
    unordered_map<string, int> m;
    //to insert the values in the multi map
    m.emplace("tv", 100);
    m.emplace("watch", 300);
    m.emplace("tablet", 200);
    m.emplace("camera", 150);


    for(auto p : m){
        cout << p.first << " " << p.second << endl;
    }
    cout << endl;
    
    return 0;
}