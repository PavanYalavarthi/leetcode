/*
problem credits: https://leetcode.com/problems/shifting-letters-ii/

You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.

Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').

Return the final string after all such shifts to s are applied.

Solution:
    Sweep line algorithm
*/
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int>sweepline(n+1, 0);
        for(auto&shift: shifts) {
            int direction = (shift[2] == 0) ? -1 : 1;
            sweepline[shift[0]] += direction %= 26;
            sweepline[shift[1]+1] -= direction %= 26;
        }
        partial_sum(sweepline.begin(), sweepline.end(), sweepline.begin());
        for(int i = 0; i < n; i++) {
            s[i] = (s[i] - 'a' + sweepline[i]) % 26 + 'a';
            if (s[i] < 'a') s[i] += 26;
        }
        return s;
    }
};