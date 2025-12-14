/*
problem credits: https://leetcode.com/problems/contains-duplicate-ii/

Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

SOlution: Hash element with index and see its repetition lies within k
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for (int i =0; i< nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end() && i - mp[nums[i]]  <= k) {
                return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};