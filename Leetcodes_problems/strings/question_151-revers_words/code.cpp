#include<iostream>
#include<vector>
using namespace std;

string reverseWords(string s) {
    //1) We would need to reverse the whole string. 
    //2) detect the words and access them without the spaces. 
    //3) remove the extra space and reverse the words again. 

    //Lets reverse the whole string using the revers function. 
    string ans = "";
    reverse(s.begin(), s.end());

    //now traverse over the reversed string. 
    for(int i = 0; i < s.length(); i++){
        string word = "";
        while(s[i] != ' ' && i < s.length()){// this while loop will assist us to find the word. Word is basically without any space. It has only alphanumeric characters. 
            word += s[i];
            i++;
        }

        //Now have the word, we would need to reverse it again. 
        reverse(word.begin(), word.end());
        if(word.length() > 0){
            ans += " " + word;
        }
    }
    return ans.substr(1);
}

 
int main()
{

    string s = "a good   example";
    cout << reverseWords(s);
    return 0;
}