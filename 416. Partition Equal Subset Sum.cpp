/*
problem credits: https://leetcode.com/problems/partition-equal-subset-sum/

Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.


SOlution:
    solve(i, j) => if there exist solution till i with sum j
                = solve(i - 1, j)   //Not picking ith element
                    || solve(i-1, j - nums[i]) //picking ith element


Belowe  version is space optimized version of the same
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        vector<bool>dp(sum/2 +1, false);
        dp[0] = true;
        for(int num: nums) {
            for(int i = sum/2; i>= num; i--) {
                dp[i] = dp[i] || dp[i-num];
            }
        }
        return dp[sum/2];
    }
};