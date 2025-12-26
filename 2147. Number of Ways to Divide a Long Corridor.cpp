/*
Problem credits: https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/description/

Along a long library corridor, there is a line of seats and decorative plants. You are given a 0-indexed string corridor of length n consisting of letters 'S' and 'P' where each 'S' represents a seat and each 'P' represents a plant.

One room divider has already been installed to the left of index 0, and another to the right of index n - 1. Additional room dividers can be installed. For each position between indices i - 1 and i (1 <= i <= n - 1), at most one divider can be installed.

Divide the corridor into non-overlapping sections, where each section has exactly two seats with any number of plants. There may be multiple ways to perform the division. Two ways are different if there is a position with a room divider installed in the first way but not in the second way.

Return the number of ways to divide the corridor. Since the answer may be very large, return it modulo 109 + 7. If there is no way, return 0.

Solution:
    Keep array of indices where sofa is present,

    We can place divider any where from 2*i and 2*i+1 sofa. SO multiply to ans the length between them
*/

#define MOD 100000007
class Solution {
public:
    int numberOfWays(string corridor) {
        vector<int>sofaIndex;
        for(int i =0; i< corridor.size(); i++) {
            if (corridor[i] == 'S') {
                sofaIndex.push_back(i);
            }
        }
        int n = sofaIndex.size();
        if (n == 0 || n % 2 == 1) return 0;
        long long ans = 1;
        int prev = sofaIndex[1];
        for(int i = 2; i < n; i+=2) {
            int len = (sofaIndex[i] - prev);
            ans = (ans * len) % MOD;
            prev = sofaIndex[i+1];
        }
        return (int)ans;
    }
};