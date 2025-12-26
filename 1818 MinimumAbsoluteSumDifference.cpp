/*
problem credits: https://leetcode.com/problems/minimum-absolute-sum-difference/description/

You are given two positive integer arrays nums1 and nums2, both of length n.

The absolute sum difference of arrays nums1 and nums2 is defined as the sum of |nums1[i] - nums2[i]| for each 0 <= i < n (0-indexed).

You can replace at most one element of nums1 with any other element in nums1 to minimize the absolute sum difference.

Return the minimum absolute sum difference after replacing at most one element in the array nums1. Since the answer may be large, return it modulo 109 + 7.

Solution: 
        
*/
#define MOD 1000000007
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int original = 0, n = nums1.size();
        vector<int>diff(n);
        for(int i =0; i <n; i++) {
            diff[i] =  abs(nums1[i] - nums2[i]) % MOD;
            original = (original + diff[i]) % MOD;
        }
        sort(nums1.begin(), nums1.end());
        int max_diff = 0;
        for(int i =0; i < n; i++) {
            int ele = nums2[i];
            int index = lower_bound(nums1.begin(), nums1.end(), ele) - nums1.begin();
            int updated = INT_MAX;
            if (index != n) updated = min(updated, nums1[index] - ele);
            if (index != 0) updated = min(updated, ele - nums1[index - 1]);
            max_diff = max(max_diff, (diff[i] - updated + MOD) %MOD);
        }
        return (original - max_diff + MOD)%MOD;
    }
};