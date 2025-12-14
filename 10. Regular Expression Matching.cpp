/*
Problem credits: https://leetcode.com/problems/regular-expression-matching/

Statement: 
    Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

    '.' Matches any single character .
    '*' Matches zero or more of the preceding element.
    The matching should cover the entire input string (not partial).

Solution:
    use DP, 
    dp[i][j] => whether s[0..i-1] matches p[0..j-1]

    When j-1 is *
        1. Neglecting it, dp[i][j-2]
        2. matching one occurance (i.e, removing index) and keeping j as is (i > 0 && (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j])
    else,
        match chars and dp[i-1][j-1]
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        bool dp[n+1][m+1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        
        for(int i=0; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-2] || (i > 0 && (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]);
                }
                else{
                    dp[i][j] = i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
            }
        }
        
        return dp[n][m];
    }
};