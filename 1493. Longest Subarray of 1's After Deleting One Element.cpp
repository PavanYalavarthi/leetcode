/*
Problem credits: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

Solution:
    keep expanding and shrinking window to zero count == 1 and find the biggest window
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), left = 0, zeros = 0, ans = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) zeros++;
            if (zeros > 1) {
                if (nums[left] == 0) zeros--;
                left++;
            }
            ans = max(ans, right - left);
        }
        return ans;
    }
};