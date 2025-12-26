/*
Problem credits: https://leetcode.com/problems/make-sum-divisible-by-p/

Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

A subarray is defined as a contiguous block of elements in the array.

Solution:
    First count whats extra sum we had on sum of whole array. if taregt is 0, then return 0;

    Else needed to find subarray with sum target, so that can be removed. find the smallest amoung them
*/
class Solution {
public:
    int minSubarray(vector<int>& nums, int k) {
        int sum = 0, n = nums.size();
        for(int num: nums) {
            sum = (sum + num) % k;
        }
        int target = sum % k;
        if (target == 0) return 0;
        unordered_map<long long, int>mp;
        mp[0] = -1;
        int cur_sum = 0;
        int minLen = n;
        for(int i =0 ;i <n; i++) {
            cur_sum = (cur_sum + nums[i]) % k;
            int needed = (cur_sum - target + k) % k;
            if (mp.count(needed)) {
                minLen = min(minLen, i - mp[needed]);
            }
            mp[cur_sum] = i;
        }
        return minLen == n ? -1 : minLen;
    } 
};