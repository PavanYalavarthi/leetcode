/*
Problem credits: https://leetcode.com/problems/contains-duplicate/

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Solution: Saving in set and returning true if element present in set
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++)
            if (!(s.insert(nums[i]).second)) 
                return true;
        return false;
    }
};