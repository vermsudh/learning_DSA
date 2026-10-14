#include<iostream>
#include<map>
using namespace std;
 
int main()
{   
    map<string, int> m;
    m["tv"] = 100;
    m["laptop"] = 50;
    m["headphopnes"] = 30;
    m["tablet"] = 25;
    m["watch"] = 60;
    for(auto p : m){
        cout << p.first << " " << p.second << endl;
    }
    cout << endl;
    //to insert the values in the map
    m.emplace("camera", 250);
    for(auto p : m){
        cout << p.first << " " << p.second << endl;
    }
    cout << endl;

    cout << "count = " << m.count("laptop") << endl;
    cout << "count = " << m["laptop"] << endl;
    cout << endl;
    m.erase("tv");
    for(auto p : m){ cout << p.first << " " << p.second << endl;}
    cout << endl;
    if(m.find("camera") != m.end()){
        cout << "found\n";
    }else{
        cout << "not found\n";
    }
    
    return 0;
}