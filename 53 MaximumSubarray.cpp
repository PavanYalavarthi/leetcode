/*
Problem credits: https://leetcode.com/problems/maximum-subarray/

Given an integer array nums, find the subarray with the largest sum, and return its sum.

Solution: Kadane's algorithm
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN, sum = 0;
        for(int num: nums) {
            sum = max(num, sum + num);
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};