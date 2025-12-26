/*
problem credits: https://leetcode.com/problems/running-sum-of-1d-array/

Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.

Solution: using prefix sum (or partial_sum of STL)
*/
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>ans(nums.size());
        partial_sum(nums.begin(), nums.end(), ans.begin());
        return ans;
    }
};