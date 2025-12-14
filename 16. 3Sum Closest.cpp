/*
Problem credits: https://leetcode.com/problems/3sum-closest/description/

Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.


Solution:
    Sort + Two pointer and get min abs diff.
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX/2, n = nums.size();
        for(int i = 0; i < n; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < abs(ans - target)) {
                    ans = sum;
                } else if (sum < target) {
                    j++;
                } else if (sum > target){
                    k--;
                } else {
                    return sum;
                }
            }
        }
        return ans;
    }
};