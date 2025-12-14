/*
Problem credits: https://leetcode.com/problems/house-robber/

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.


Solution:
    using dp, 
    rob current house => max(amount[i] + rob(i-2), rob(i-1))
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        return rob(nums, 0, nums.size());
    }

    int rob(vector<int>& nums, int start, int end) {
        int prev1 = 0, prev2 =0, temp;
        for(int i = start; i< end; i++) {
            temp = prev1;
            prev1 = max(nums[i] + prev2, prev1);
            prev2 = temp;
        }
        return prev1;
    }
};