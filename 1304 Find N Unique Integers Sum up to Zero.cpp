/*
Problem credits: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/description/

Given an integer n, return any array containing n unique integers such that they add up to 0.

Solution: 
    push x, -x, for x from -1 to -n/2
    and add 0 if n is odd
*/
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n);
        res[0] = n * (1 - n) / 2;
        for (int i = 1; i < n; ++i)
            res[i] = i;
        return res;
    }
};