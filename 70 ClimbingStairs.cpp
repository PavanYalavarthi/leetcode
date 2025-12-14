/*
Problem credits: https://leetcode.com/problems/climbing-stairs/

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Solution: F(n) = F(n-1) + F(n-2) => fibonnaci series
*/

class Solution {
public:
    int climbStairs(int n) {
        if (n < 4) return n;
        int c;
        for(int i = 4, a = 2, b = 3, temp; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};