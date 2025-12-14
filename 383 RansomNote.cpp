/*
problem credits: https://leetcode.com/problems/ransom-note/

Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.


Solution: Calculating freq of each char in magazine and decrementing the same for evry char in ransomNote. If count becomes 0 before decrement returning false. else true
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int m = ransomNote.size(), n = magazine.size();
        if ( m > n) return false;
        int freq[26] = {0};
        for (char c : magazine) {
            freq[c - 'a']++;
        }
        for (char c : ransomNote) {
            int &freq_c = freq[c - 'a'];
            if (freq_c == 0) return false;
            freq_c--; 
        }
        return true;
    }
};