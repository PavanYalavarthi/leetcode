/*
Problem credits: https://leetcode.com/problems/k-inverse-pairs-array/

For an integer array nums, an inverse pair is a pair of integers [i, j] where 0 <= i < j < nums.length and nums[i] > nums[j].

Given two integers n and k, return the number of different arrays consisting of numbers from 1 to n such that there are exactly k inverse pairs. Since the answer can be huge, return it modulo 109 + 7.

Solution:
    inversion count ranges from 0 to n-1.(picking smallest number to largest) So, doing the same
*/
#define MOD 1000000007
class Solution {
public:
    int kInversePairs(int n, int k) {
        int dp[2][1001] = { 1 };
        for (int N = 1; N <= n; ++N) {
            for (int K = 0; K <= k; ++K) {
                dp[N % 2][K] = (dp[(N - 1) % 2][K] + (K > 0 ? dp[N % 2][K - 1] : 0)) % MOD;
                if (K >= N)
                    dp[N % 2][K] = (MOD + dp[N % 2][K] - dp[(N - 1) % 2][K - N]) % MOD;
            }
        }
        return dp[n % 2][k];
    }
};