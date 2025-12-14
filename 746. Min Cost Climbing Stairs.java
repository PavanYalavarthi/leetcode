/*
Problem credits: https://leetcode.com/problems/min-cost-climbing-stairs/

You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

Solution: 
    dp[i] => cost till i, when ith stair cost is paid. => dp[i] = cost[i] + min(dp[i-1], dp[i-2])

    And ans is min(dp[n-1], dp[n-2])
*/

class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int a = cost[0], b =cost[1], c;
        for(int i = 2; i < cost.length ;i++){
            c = cost[i] + Math.min(a,b);
            a = b;
            b = c;
        }
        return Math.min(a,b);
    }
}