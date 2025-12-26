/*
Problem credits: https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/

You are given an integer array nums.

In one move, you can choose one element of nums and change it to any value.

Return the minimum difference between the largest and smallest value of nums after performing at most three moves.

Solution:
    min 3 or max 3 can be changed. So, find diff between nums[i] and nums[n-4+i] for i = 0 .. 3
*/
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) return 0;
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for(int i = 0; i < 4; i++) {
            ans = min(ans, nums[n - 4 + i] - nums[i]);
        }
        return ans;
    }
};