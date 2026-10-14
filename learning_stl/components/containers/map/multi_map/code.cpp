#include<iostream>
#include<map>
using namespace std;
 
int main()
{
    multimap<string, int> m;
    //to insert the values in the multi map
    m.emplace("tv", 100);
    m.emplace("tv", 100);
    m.emplace("tv", 100);
    m.emplace("tv", 100);
    //to delete any key and value in multimap
    m.erase(m.find("tv"));

    for(auto p : m){
        cout << p.first << " " << p.second << endl;
    }
    cout << endl;
    
    return 0;
}