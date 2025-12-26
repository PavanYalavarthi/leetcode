/*
problem credits: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/

You are given an integer array prices where prices[i] is the price of a stock in dollars on the ith day, and an integer k.

You are allowed to make at most k transactions, where each transaction can be either of the following:

Normal transaction: Buy on day i, then sell on a later day j where i < j. You profit prices[j] - prices[i].

Short selling transaction: Sell on day i, then buy back on a later day j where i < j. You profit prices[i] - prices[j].

Note that you must complete each transaction before starting another. Additionally, you can't buy or sell on the same day you are selling or buying back as part of a previous transaction.

Return the maximum total profit you can earn by making at most k transactions.

Solution:
    Comments in the code
*/
#define ll long long
class Solution {
    ll minVal = -1e9;
    ll dp[1001][501][3];
public:
    long long helper(int index, int k, int status, vector<int>& prices) {
        if (index == prices.size()) return (status == 0) ? 0 : minVal;
        if (k == 0) return 0;
        ll& ans = dp[index][k][status];
        if (ans != minVal) return ans;
        //Skip
        ans = helper(index+1, k, status, prices);

        if (status == 0) {
            //Start new transaction
            ans = max(ans, helper(index+1, k, 1, prices) - prices[index]);
            ans = max(ans, helper(index+1, k, 2, prices) + prices[index]);
        } else {
            //Close the existing transaction
            if (status == 1) ans = max(ans, helper(index+1, k-1, 0, prices) + prices[index]);
            else ans = max(ans, helper(index+1, k-1, 0, prices) - prices[index]);
        }
        return ans;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp) / sizeof(ll), minVal);
        return helper(0, k, 0, prices);
    }
};