/*
problem credits: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).

Solution: needed to count from high - number of odds below low

SO  (high + 1) / 2 - low / 2
*/
class Solution {
public:
    int countOdds(int low, int high) {
        return (high + 1) / 2 - low / 2;
    }
};