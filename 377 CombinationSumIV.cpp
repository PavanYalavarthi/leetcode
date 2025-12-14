/*
Problem credits: https://leetcode.com/problems/combination-sum-iv/

Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.

Solution:
    use dp to store #combinations to get target t
*/
class Solution {
    unordered_map<int, int> dp = {{0, 1}};
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (auto it = dp.find(target); it != dp.end()) return it->second;
        int ans = 0;
        for (int num: nums) {
            if (target >= num) 
                ans += combinationSum4(nums, target - num);
        }
        return dp[target] = ans;
    }
};