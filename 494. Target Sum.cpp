/*
Problem credits: https://leetcode.com/problems/target-sum/description/

You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Solution:
    we can group +ves and -ves as separate group. that means p + n = sum and p - n = target = > p = (sum + target) / 2

    It transformed to Partion subset with given sum. refer leetcode 416
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < abs(target) || ((sum + target) & 1)) return 0;
        int k = (sum + target) / 2;
        vector<int>dp(k+1, 0);
        dp[0] = 1;
        for(int num: nums) {
            for(int i = k; i >= num; i--) {
                dp[i] += dp[i - num];
            }
        }
        return dp[k];
    }
};