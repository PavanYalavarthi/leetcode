/*
Problem credits: https://leetcode.com/problems/minimum-absolute-difference-between-elements-with-constraint/description/

You are given a 0-indexed integer array nums and an integer x.

Find the minimum absolute difference between two elements in the array that are at least x indices apart.

In other words, find two indices i and j such that abs(i - j) >= x and abs(nums[i] - nums[j]) is minimized.

Return an integer denoting the minimum absolute difference between two elements that are at least x indices apart.

Solution:
    As abs(i-j) needed to be >= x, need to start from index x

    and see diff bwteen numbers around nums[i] with nums[i] and get minimum of it
*/
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set<int>s;
        int ans = INT_MAX;
        for(int i = x; i< nums.size(); i++) {
            s.insert(nums[i - x]);
            auto it = s.lower_bound(nums[i]);
            if (it != s.end()) ans = min(ans, *it - nums[i]);
            if (it != s.begin()) ans = min(ans, nums[i] - *prev(it));
        }
        return ans;
    }
};