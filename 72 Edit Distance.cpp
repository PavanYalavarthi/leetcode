class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return helper(word1, word2, m, n, dp);
    }

    int helper(string w1, string w2, int i, int j, vector<vector<int>> &dp) {
        if(i == 0 || j == 0) return i + j;
        if(dp[i][j] != -1) return dp[i][j];
        if (w1[i-1] == w2[j-1]) return dp[i][j] = helper(w1, w2, i -1, j-1, dp);
        return dp[i][j] = 1 + min({helper(w1,w2,i, j-1, dp), helper(w1,w2,i -1, j, dp), helper(w1,w2,i -1, j -1, dp)});
    }
};