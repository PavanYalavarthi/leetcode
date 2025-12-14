/*
Problem credits: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Solution: Always keep max price, and get profit => max_price - price
*/

/*
 * Time complexity : O(n)
 * Space complexity : O(1)
 * keep updating the min price, else check the max profit you can get
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0], profit = 0;
        for (int price : prices) {
            if (price < min) min = price;
            else profit = max(profit, price - min);
        }
        return profit;
    }
};