/*
Problem credits: https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/

You are given an integer array nums and two integers minK and maxK.

A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

The minimum value in the subarray is equal to minK.
The maximum value in the subarray is equal to maxK.
Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.

Solution:
    For all subarrays ending at i, we can pick [bad_idx + 1 ... min(min_idx, max_idx)] , so incrementing ans with max(0, min(min_idx, max_idx) - bad_idx)
*/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int bad_idx = -1, min_idx = -1, max_idx = -1;
        for(int i = 0; i < nums.size(); i++) {
            int ele = nums[i];
            if (ele > maxK || ele < minK) bad_idx = i;
            else  {
                if (ele == minK) min_idx = i;
                if (ele == maxK) max_idx = i;
            }
            ans += max(0, min(min_idx, max_idx) - bad_idx);
        }
        return ans;
    }
};