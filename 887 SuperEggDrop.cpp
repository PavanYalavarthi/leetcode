/*
Problem description: https://leetcode.com/problems/super-egg-drop/

You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

Solution:
    Pick mid and check if broken < non_broken, then we can drop on bigger floor else lower floor
*/
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