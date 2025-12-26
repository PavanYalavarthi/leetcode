/*
problem credits: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

Solution:
    use 2 pointer and multiset to find max and min in the range.
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int>s;
        int ans = 0;
        for(int l = 0, r = 0; r < nums.size(); r++) {
            s.insert(nums[r]);
            while (*s.rbegin() - *s.begin() > limit) {
                s.erase(s.find(nums[l++]));
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};