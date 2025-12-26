/*
Problem credits: https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/description/

You are given a string s consisting of lowercase English letters.

Your task is to find the maximum difference diff = freq(a1) - freq(a2) between the frequency of characters a1 and a2 in the string such that:

a1 has an odd frequency in the string.
a2 has an even frequency in the string.
Return this maximum difference

Solution:
    Pick max of odd freq and min of even freq
*/
class Solution {
public:
    int maxDifference(string s) {
        int freq[26] = {0};
        for(int i = 0; i < s.size(); i++) freq[s[i] - 'a']++;
        int oddFreq = 0, evenFreq = 99;
        for(int j = 0, i; j< 26; j++) {
            i = freq[j];
            if (i != 0) {
                if (i & 1) oddFreq = max(oddFreq, i);
                else evenFreq = min(evenFreq, i);
            }
        }
        return oddFreq - evenFreq;
    }
};