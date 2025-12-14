/*
problem credits: https://leetcode.com/problems/counting-bits/

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

Solution:
    Use res[i] = res[i >> 1] + (i & 1);
*/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>res(n+1);
        res[0] = 0;
        for(int i= 1; i< res.size(); i++)
            res[i] = res[i >> 1] + (i & 1);
        return res;
    }
};