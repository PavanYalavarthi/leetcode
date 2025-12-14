/*
Problem credits: https://leetcode.com/problems/continuous-subarray-sum/

Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

A good subarray is a subarray where:

its length is at least two, and
the sum of the elements of the subarray is a multiple of k.

Solution:
    Keep sum%k in hashmap and check whether it exists. The index shouldn't be i-1 to ensure the length is atlast 2

*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum = (sum + nums[i]) %k;
            if(mp.count(sum)) {
                if (mp[sum] != i - 1)
                    return true;
            } else {
                mp[sum] = i;
            }
        }
        return false;
    }
};