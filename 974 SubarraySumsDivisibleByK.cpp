/*
problem credits: https://leetcode.com/problems/subarray-sums-divisible-by-k/

Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

Solution: 
    prefix sum and hash the previous sum
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp{{0, 1}};
        int sum = 0, count = 0;
        for(int i = 0; i< nums.size(); i++) {
            (sum += nums[i] % k + k) %= k;
            count += mp[sum]++;
        }
        return count;
    }
};