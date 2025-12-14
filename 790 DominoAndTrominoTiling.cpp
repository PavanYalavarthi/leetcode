/*

Problem credits: https://leetcode.com/problems/domino-and-tromino-tiling/

Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

Solution:
    f(n) = f(n-1) // when used vertical domino
            + f(n-2) //When used horizontal domino
            + 2 * (f(n-3) + f(n-4) +  .. + f(0)) // when used tromino (only single for compensation trimino) as the trimino can be inverted x 2
    f(n) - f(n - 1) = f(n-1) + f(n-3) => f(n) = 2 * f(n -1) + f(n-3);
*/

class Solution {
    const int MOD = 1e9 + 7;
public:
    int numTilings(int n) {
        if (n < 2) return 1;
        vector<uint> dp(n + 1);
        dp[0] = 1, dp[1] = 1, dp[2] = 2;
        for(int i = 3; i <= n; i++) {
            dp[i] = ((2 * dp[i - 1] % MOD) + dp[i-3]) % MOD;
        }
        return (int)dp[n];
    }
};