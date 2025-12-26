/*
Problem credits: https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/description/

You are given an integer array prices representing the daily price history of a stock, where prices[i] is the stock price on the ith day.

A smooth descent period of a stock consists of one or more contiguous days such that the price on each day is lower than the price on the preceding day by exactly 1. The first day of the period is exempted from this rule.

Return the number of smooth descent periods.


Solution:
    keep counting the sequence and keep adding the sequence length to the ans
*/

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int cnt = 1;
        long long ans = 1;
        for(int i = 1; i < prices.size(); i ++) {
            if(prices[i] == prices[i - 1] - 1) {
                cnt++;
            } else {
                cnt = 1;
            }
            ans += cnt;
        }
        return ans;
    }
};