/*
problem credits: https://leetcode.com/problems/paint-house-iii/

There is a row of m houses in a small city, each house must be painted with one of the n colors (labeled from 1 to n), some houses that have been painted last summer should not be painted again.

A neighborhood is a maximal group of continuous houses that are painted with the same color.

For example: houses = [1,2,2,3,3,2,1,1] contains 5 neighborhoods [{1}, {2,2}, {3,3}, {2}, {1,1}].
Given an array houses, an m x n matrix cost and an integer target where:

houses[i]: is the color of the house i, and 0 if the house is not painted yet.
cost[i][j]: is the cost of paint the house i with the color j + 1.
Return the minimum cost of painting all the remaining houses in such a way that there are exactly target neighborhoods. If it is not possible, return -1.

 
Solution:
    dp[i][count][prev] => cost of painiting i houses, with count neigborhood remaining with prev color prev
*/
class Solution {
public:
    int dp[105][105][25];
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int ans = func(houses,cost,target,0,0);
        if(ans>=1e9) return -1;
        return ans;
    }

    int func(vector<int>& houses, vector<vector<int>>& cost, int count, int i, int prev) {
        if (count < 0) return 1e9;
        if( i == houses.size()) {
            if (count == 0) return 0;
            else return 1e9;
        }
        if (dp[i][count][prev] != -1) return dp[i][count][prev];
        if (houses[i] != 0) {
            return dp[i][count][prev] = func(houses, cost, count - (prev != houses[i]), i +1, houses[i]);
        } else {
            int ans = 1e9;
            for (int k = 0; k <cost[i].size(); k++) {
                ans = min(ans, cost[i][k] + func(houses, cost, count - (k + 1 != prev), i + 1, k +1));
            }
            return dp[i][count][prev] = ans;
        }
        return 1e9;
    }
};