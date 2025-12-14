/*
Problem credits: https://leetcode.com/problems/coin-change-ii/

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

Solution:
    dp[i] => #combination make amount i; dp[i] = sum of dp[i - coins[j]] for j 0.. n
*/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long>dp(amount+1, 0);
        dp[0] = 1;
        for(int coin: coins){
            for(int i = coin; i <= amount; i++){
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};