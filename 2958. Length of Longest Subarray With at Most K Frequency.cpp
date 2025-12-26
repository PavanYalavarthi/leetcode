/*
problem credits: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/

You are given an integer array nums and an integer k.

The frequency of an element x is the number of times it occurs in an array.

An array is called good if the frequency of each element in this array is less than or equal to k.

Return the length of the longest good subarray of nums.

A subarray is a contiguous non-empty sequence of elements within an array.


Solution:
    Sliding window, making sure the freq of right char not > k
*/
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans = 0;
        for(int start= 0, end =0; end<nums.size(); end++) {
            mp[nums[end]]++;
            while(mp[nums[end]] > k)
                mp[nums[start++]]--;
            ans = max(ans, end - start + 1); 
        }
        return ans;
    }
};