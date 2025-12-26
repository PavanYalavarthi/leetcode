/*
problem credits: https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/description/

You are given an integer array nums sorted in non-decreasing order.

Build and return an integer array result with the same length as nums such that result[i] is equal to the summation of absolute differences between nums[i] and all the other elements in the array.

In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j < nums.length and j != i (0-indexed).


Solution:
    nums[i] * i - prefix[i] + suff[i+1] - nums[i] * (n - i - 1) is the ans at ith index
*/
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n+1), suff(n+1);
        prefix[0] = suff.back() = 0;
        partial_sum(nums.begin(), nums.end(), prefix.begin() + 1);
        partial_sum(nums.rbegin(), nums.rend(), suff.rbegin() + 1);
        vector<int>ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = nums[i] * i - prefix[i] + suff[i+1] - nums[i] * (n - i - 1);
        }
        return ans;
    }
};