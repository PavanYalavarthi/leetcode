/*
Problem credits: https://leetcode.com/problems/trapping-rain-water/

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Solution: Take extremes and pop out the minimal height, while updating max height on both ends.
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int l = 0, r = n - 1;
        int lmax = 0, rmax = 0, ans = 0;

        while (l <= r) {
            if (height[l] <= height[r]) {
                if (height[l] >= lmax) lmax = height[l];
                else ans += lmax - height[l];
                l++;
            } else {
                if (height[r] >= rmax) rmax = height[r];
                else ans += rmax - height[r];
                r--;
            }
        }
        return ans;
    }
};