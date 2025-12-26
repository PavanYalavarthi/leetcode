/*
problem credits: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-using-strategy/description/

You are given two integer arrays prices and strategy, where:

prices[i] is the price of a given stock on the ith day.
strategy[i] represents a trading action on the ith day, where:
-1 indicates buying one unit of the stock.
0 indicates holding the stock.
1 indicates selling one unit of the stock.
You are also given an even integer k, and may perform at most one modification to strategy. A modification consists of:

Selecting exactly k consecutive elements in strategy.
Set the first k / 2 elements to 0 (hold).
Set the last k / 2 elements to 1 (sell).
The profit is defined as the sum of strategy[i] * prices[i] across all days.

Return the maximum possible profit you can achieve.

Note: There are no constraints on budget or stock ownership, so all buy and sell operations are feasible regardless of past actions.

Solution:
    Check sum of left of the window and right of window. And sum of indices window/2 to window.
*/

#define ll long long
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<ll> profitPrefix(n+1), pricePrefix(n+1);
        profitPrefix[0] = pricePrefix[0] = 0;
        for(int i = 1;i <= n; i++) {
            profitPrefix[i] = profitPrefix[i-1] + strategy[i-1] * prices[i-1];
            pricePrefix[i] = pricePrefix[i-1] + prices[i-1];
        }
        ll ans = profitPrefix.back();
        for(int right = k; right <= n; right++) {
            int left = right - k + 1;
            ll leftProfit = profitPrefix[left - 1];
            ll rightProfit = profitPrefix[n] - profitPrefix[right];
            ll changePrice = pricePrefix[right] - pricePrefix[right - k/2];
            ans = max(ans, leftProfit + rightProfit + changePrice);
        }
        return ans;
    }
};