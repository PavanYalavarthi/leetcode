/*
problem credits: https://leetcode.com/problems/house-robber-ii/

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.


Solution: As it is circle, we can only rob first or last house in successful rob.

So, take max(robing 1..n-1, robing 2 .. n)
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(rob(nums, 0,n-1), rob(nums, 1, n));
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