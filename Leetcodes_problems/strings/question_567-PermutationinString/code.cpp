#include<iostream>
#include<vector>
using namespace std;

bool isFreqSame(int freq1[], int freq2[]){
    for(int i = 0; i < 26; i++){
        if(freq1[i] != freq2[i]){
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2){
    //first, lets get the frequency of each character in s1

    int freq[26] = {0};
    
    for(int i = 0; i < s1.length(); i++){
        int index = s1[i] - 'a';    
        freq[index]++;
    }

    for(int i = 0; i < s2.length(); i++){
        int windFreq[26] = {0};
        int windowSize = s1.length();
        int index = i, windowIndex = 0;

        while(windowSize > windowIndex && index < s2.length()){
            windFreq[s2[index] - 'a']++;
            windowIndex++; index++;
        }

        if(isFreqSame(windFreq, freq)){
            return true;
        }

    }
    return false;

}
 
int main()
{
    string s1 = "ab", s2 = "eidbaooo";

    cout << checkInclusion(s1, s2);

    return 0;
}