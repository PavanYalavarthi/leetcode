class Solution {
public:
    int helper(string& s, int i, int j, int k,  vector<vector<vector<int>>>& dp) {
        if (i >= j) {
            return i ==j;
        }
        int &ans = dp[i][j][k];
        if (ans != -1) return ans;
        ans = max(helper(s, i, j-1, k, dp), helper(s, i+1, j, k, dp));
        int diff = min(abs(s[i] - s[j]), 26 - abs(s[i] - s[j]));
        if (k >= diff) {
            ans = max(ans, 2 + helper(s, i+1, j-1, k-diff, dp));
        }
        return ans;
    }
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(n, vector<int>(k+1, -1)));
        return helper(s, 0, n-1, k, dp);
    }
};