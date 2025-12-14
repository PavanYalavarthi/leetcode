/*
Problem credits: https://leetcode.com/problems/longest-palindromic-substring/

Given a string s, return the longest palindromic substring in s.

Solution: Manacher algorithm

*/
class Solution {
public:
    string longestPalindrome(string s) {
        s = "^" + regex_replace(s, regex(""), "#") + "$";
        int n = s.size();
        string ans;
        vector<int>radius(n, 0);
        int l = 0, r = 1;
        for(int i =1; i < n-1; i++) {
            int mirror = (l + r) - i;
            radius[i] = min(r - i, radius[mirror]);
            while (s[i - radius[i]] == s[i+radius[i]]) {
                radius[i]++;
            }
            if (i + radius[i] > r) {
                l = i - radius[i];
                r = i + radius[i];
                int sz = 2* radius[i] - 1;
                if (ans.size() < sz) {
                    ans = s.substr(l+1, sz);
                }
            }
        }
        return regex_replace(ans, regex("#"), "");
    }
};