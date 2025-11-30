class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<int>dp(n + 1, 0);
        for(int i = 1; i <= m; i++) {
            for(int j = 1, prev = 0, val; j <= n; j++) {
                val = prev;
                prev = dp[j];
                if (text1[i - 1] == text2[j - 1]) dp[j] = 1 + val;
                else dp[j] = max(dp[j], dp[j-1]);
            }
        }
        return dp[n];
    }
};