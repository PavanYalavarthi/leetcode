/*
Problem credits: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/

You are given an integer array nums and a positive integer k.

Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

A subarray is a contiguous sequence of elements within an array.

Solution:
    Sliding window, once count becomes >= k, for every start point, we can pick any from end to n -1
*/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long start = 0, end = 0, count = 0, ans = 0, mx = *max_element(nums.begin(), nums.end());
        do{
            if(nums[end] == mx) count++;
            while(count >= k) {
                if(nums[start++] == mx) count--;
                ans += nums.size() - end;
            }
        }while(++end < nums.size());
        return ans;
    }
};