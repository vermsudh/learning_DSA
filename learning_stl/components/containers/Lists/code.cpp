#include<iostream>
#include<list>
using namespace std;
 
int main()
{

    list<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    for(int val: l){cout << val << " ";}
    cout << endl;
    l.pop_back();
    l.pop_back();

    for(int val: l){cout << val << " ";}

    return 0;
}