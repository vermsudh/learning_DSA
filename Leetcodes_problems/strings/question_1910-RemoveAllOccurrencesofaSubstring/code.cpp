#include<iostream>
#include<vector>
using namespace std;

string removeOccurrences(string s, string part) {
    //1) we are going to use STL library in order to solve the question
    //str.find(substr); => str.find(part)
    // 2) str.erase(start, end); to erase the substring

    s.find(part);
    cout << s << endl;
    cout << s.find(part) << endl;

    return "";

}

int main()
{
    string s = "daabcbaabcbc";
    string part = "abc";

    removeOccurrences(s, part);

    return 0;
}