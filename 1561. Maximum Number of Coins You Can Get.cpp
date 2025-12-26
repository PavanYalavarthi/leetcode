/*
Problem credits: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/

There are 3n piles of coins of varying size, you and your friends will take piles of coins as follows:

In each step, you will choose any 3 piles of coins (not necessarily consecutive).
Of your choice, Alice will pick the pile with the maximum number of coins.
You will pick the next pile with the maximum number of coins.
Your friend Bob will pick the last pile.
Repeat until there are no more piles of coins.
Given an array of integers piles where piles[i] is the number of coins in the ith pile.

Return the maximum number of coins that you can have.

Solution:
    Always give smallest to bod, largest to Alice and pick second largest to maximize your coins
*/
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size(), j = n, sum =0;
        for(int i = 0; i< n/3;i++){
            sum += piles[j-=2];
        }
        return sum;
    }
};