/*
Problem credits: https://leetcode.com/problems/4sum-ii/

Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0


Solution:
    Meet in the middle, get all combinations of i+j and now count #combinations for -(k+l)
*/
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mp12;
        for(int i: nums1)
            for(int j: nums2)
                mp12[i+j]++;
        int ans = 0;
        for(int k: nums3)
            for(int l: nums4)
                ans += mp12[-(k+l)];
        return ans;
    }
};