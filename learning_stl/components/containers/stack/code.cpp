#include<iostream>
#include<stack>
using namespace std;
 
int main()
{

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.top(); //3
    s.pop();
    cout << endl;
    cout << s.top(); //2

    cout << endl;

    s.push(3);
    s.push(4);
    s.push(5);

    //to print the stack
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    // we can swap the stack easily using the swap function

    stack<int> s2;

    s2.swap(s);
    cout << endl;
    cout << "s size : " << s.size() << endl;
    cout << "s2 size : " << s2.size() << endl;

    return 0;
}