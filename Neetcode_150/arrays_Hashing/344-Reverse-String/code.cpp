#include<iostream>
#include<vector>
using namespace std;
 
void reverseString(vector<char>& s) {
        int left = 0, right = s.size() -1;

        while(left < right){
            if(s[left] != s[right]){
                swap(s[left], s[right]);
            }
            left ++;
            right --;
        }
}


int main()
{
    vector<char> s = {'n', 'e', 'e', 't'};
    reverseString(s);

    for(char i = 0; i < s.size(); i++){
        cout << s[i];
    }
    return 0;
}