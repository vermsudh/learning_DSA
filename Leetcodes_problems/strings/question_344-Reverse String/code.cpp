#include<iostream>
#include<vector>
using namespace std;
 
void reverseString(vector<char>& s) {
    int st = 0, end = s.size() -1;
    while(st < end){
        swap(s[st++], s[end--]);
    }
}

int main()
{

    vector<char> s = {'t', 'e', 'e' , 'n'};
    reverseString(s);

    for(char ch : s){
        cout << ch << " ";
    }
    return 0;
}