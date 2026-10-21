#include<iostream>
#include<string>
using namespace std;

string reverseWords(string s) {
    //1) we can reverse the whole string s. 
    //2) Then we need to detect the words in the string. A word is basically characters without any space. 
    //3) After we detect the word, we are going reverse the word in order to get the final output and store the ans in a new string and return that

    //lets reverse the string first.
    reverse(s.begin(), s.end());

    // Now we need to access the string using a for loop. 
    string ans = "";
    
    for(int i = 0; i < s.length(); i++){
        string word = "";
        while(s[i] != ' ' && i < s.length()){// this loop will help us to detect the word.
            word += s[i];
            i++;
        }
        //now we need to reverse the word. 
        reverse(word.begin(), word.end());

        // now, we would have to store our ans with appropriate spacing in between. 
        //For example, in each word, there should be a space. 
        if(word.length() > 0){
            ans += " " + word;
        }
    }
    return ans.substr(1);
}

 
int main()
{   
    // Example 1:

    // Input: s = "the sky is blue"
    // Output: "blue is sky the"
    // Example 2:

    // Input: s = "  hello world  "
    // Output: "world hello"
    // Explanation: Your reversed string should not contain leading or trailing spaces.
    // Example 3:

    // Input: s = "a good   example"
    // Output: "example good a"
    // Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

    string s = "a good   example";
    //output : 
    cout << reverseWords(s);
    return 0;
}