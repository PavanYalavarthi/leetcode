class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k + 1, vector<int>(n + 1, -1));
        return helper(k, n, dp);
    }

    int helper(int k, int n, vector<vector<int>>& dp) {
        if (k == 1 || n < 2) return n;
        if (dp[k][n] != -1) return dp[k][n];
        int ans = INT_MAX;
        int l = 1, h = n, mid;
        while(l <= h) {
            mid = (l + h) >> 1;
            int broken = helper(k-1, mid -1, dp);
            int notBroken = helper(k, n-mid, dp);
            ans = min(ans, 1 + max(broken, notBroken));
            if (broken < notBroken) {
                l = mid +1;
            } else {
                h = mid -1;
            }
        }
        return dp[k][n] = ans;
    }
};