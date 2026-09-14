#include<iostream>
#include<vector>
using namespace std;

bool isPalindrome(string s) {
    
    int left = 0, right = s.length() - 1;

    while(left < right){


        while(left < s.length() && !isalnum(s[left])){
            left ++;
        }
        while(right < s.length() && !isalnum(s[right])){
            right --;
        }

        if(tolower(s[left]) != tolower(s[right])){
            return false;
        }

        left ++;
        right --; 

    }
    return true;
    
}


int main()
{
    string s1 = "Was it a car or a cat I saw?";
    string s2 = "tab a cat";

    cout << isPalindrome(s1);
    cout << isPalindrome(s2);

    return 0;
}