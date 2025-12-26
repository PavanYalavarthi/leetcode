/*
problem credits: https://leetcode.com/problems/total-characters-in-string-after-transformations-i/description/

You are given a string s and an integer t, representing the number of transformations to perform. In one transformation, every character in s is replaced according to the following rules:

If the character is 'z', replace it with the string "ab".
Otherwise, replace it with the next character in the alphabet. For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.
Return the length of the resulting string after exactly t transformations.

Since the answer may be very large, return it modulo 109 + 7.

Solution:
    dp[i] => dp[i-1] after 1 transformation
*/
class Solution {
public:
    const int mod = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        vector <int> dp(t + 26);
        for (int i = 0; i < 26; i++)
            dp[i] = 1;
        for (int i = 26; i < t + 26; i++){ 
            dp[i%26] += dp[(i - 25)%26] % mod;
        }   
        int ans = 0;
        for (char ch : s) 
            ans = (ans + dp[(ch - 'a' + t)%26]) % mod;
        return ans;
    }
};