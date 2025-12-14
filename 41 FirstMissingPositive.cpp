/*
Problem credits: https://leetcode.com/problems/first-missing-positive/description/

Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

Solution: At index i, lets keep (i+1) and check first index where nums[i] != (i+1)
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i =0; i<n; i++) {
            int x = nums[i];
            while(x > 0 && x <= n && x != i + 1 && nums[x - 1] != x) {
                swap(nums[x-1], nums[i]);
                x = nums[i];
            }
        }
        for(int i = 1; i <= n; i++) {
            if (nums[i - 1] != i) 
                return i;
        }
        return n + 1;
    }
};