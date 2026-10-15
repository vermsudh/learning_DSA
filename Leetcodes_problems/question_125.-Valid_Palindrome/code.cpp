#include<iostream>
#include<vector>
using namespace std;
 
bool isAlpNum(char ch){
        if((ch >= '0' && ch <= '9')||(tolower(ch) >= 'a' && tolower(ch) <= 'z')){
            return true;
        }
        return false;
    }
    //2) Now we know how to check if any char is aplha numeric or not? 
    // Now we would have to skip those char which are not aplphanumeric or not. 
    
bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        // this step will skip those characters which are not aplhanumeric. 
        while(left < right){
            if(!isAlpNum(s[left])){
                left++; 
                continue;
            }
            if(!isAlpNum(s[right])){
                right--;
                continue;
            }
            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
     return true;
}

int main()
{
    string s = "No lemon, no melon";
    //string s = "Was it a car or a cat I saw?";

    cout << isPalindrome(s) << endl;
    
    
    return 0;
}