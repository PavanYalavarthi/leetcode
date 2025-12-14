/*

Problem credits: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

Solution: 
    As one duplicate is allowed, check for k-2 element. if it is not equal, move the ans
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();
        int k = 2;
        for(int i=2;i<nums.size();i++)
            if(nums[k-2] != nums[i])
                nums[k++] = nums[i];
        return k;
    }
};