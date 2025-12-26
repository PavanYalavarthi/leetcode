/*
Problem credits: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/

You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

The length of the subarray is k, and
All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.


Solution:
    Sliding window to have no repeated and size in k
*/
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long sum =0, ans = 0;
        for(int l =0, r =0; r < nums.size(); r++) {
            int curr = nums[r];
            int lastOccurance = mp.count(curr) ? mp[curr] : -1;
            while (l <= lastOccurance || r - l + 1 > k) {
                sum -= nums[l];
                mp.erase(nums[l]);
                l++;
            } 
            sum += nums[r];
            mp[curr] = r;
            if(mp.size() == k) {
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};