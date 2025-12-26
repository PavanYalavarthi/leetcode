/*
Problem credits: https://leetcode.com/problems/paint-house-iv/description/

You are given an even integer n representing the number of houses arranged in a straight line, and a 2D array cost of size n x 3, where cost[i][j] represents the cost of painting house i with color j + 1.

The houses will look beautiful if they satisfy the following conditions:

No two adjacent houses are painted the same color.
Houses equidistant from the ends of the row are not painted the same color. For example, if n = 6, houses at positions (0, 5), (1, 4), and (2, 3) are considered equidistant.
Return the minimum cost to paint the houses such that they look beautiful.

Solution:
    Pick color for cur house and mirroed house and add the painyting cost to it and call the function recursively
*/
class Solution {
    vector<vector<vector<long long>>> dp;
public:
    long long minCost(int n, vector<vector<int>>& cost) {
         dp.assign(n / 2 + 1, vector<vector<long long>>(4, vector<long long>(4, -1)));
        return func(cost, 0, 3, 3);
    }

    long long func(vector<vector<int>>& cost, int i, int prevColor, int prevOppColor) {
        int n = cost.size();
        if (i == n / 2) return 0;
        if(dp[i][prevColor][prevOppColor] != -1) return dp[i][prevColor][prevOppColor];
        long long ans = LONG_MAX;
        for(int color = 0; color < 3; color++) {
            if (color != prevColor) {
                for(int oppColor = 0; oppColor < 3; oppColor++) {
                    if (oppColor != prevOppColor && color != oppColor) {
                        ans = min(ans,  func(cost, i + 1, color, oppColor) + cost[i][color] + cost[n - i - 1][oppColor]);
                    }
                }
            }
        }
        return dp[i][prevColor][prevOppColor] = ans;
    }
};