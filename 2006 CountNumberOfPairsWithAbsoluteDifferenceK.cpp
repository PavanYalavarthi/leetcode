/*
Problem credits: https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/description/

Given an integer array nums and an integer k, return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.

SOlution:
    pick #ele with val num+k, num-k.
*/
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans= 0;
        for(int num:  nums) {
            ans += mp[num - k] + mp[num + k];
            mp[num]++;
        }
        return ans;
    }
};