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

bool checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length()) {
        return false;
    }

    int freq[26] = {0};
    int windowFreq[26] = {0};

    for (char ch : s1) {
        freq[ch - 'a']++;
    }

    int left = 0;

    for (int right = 0; right < s2.length(); right++) {
        // Right character enters the window.
        windowFreq[s2[right] - 'a']++;

        // Window is too large: remove its leftmost character.
        while (right - left + 1 > s1.length()) {
            windowFreq[s2[left] - 'a']--;
            left++;
        }

        // The window now has exactly s1.length() characters.
        if (right - left + 1 == s1.length() &&
            isFreqSame(freq, windowFreq)) {
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