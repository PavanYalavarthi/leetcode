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