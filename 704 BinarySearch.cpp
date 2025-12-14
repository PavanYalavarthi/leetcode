/*
Problem credits: https://leetcode.com/problems/binary-search/description/

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

Solution: Binary search
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() -1, mid;
        while (low <= high) {
            mid = (low + high)/ 2;
            if(target == nums[mid]) return mid;
            else if (target > nums[mid]) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};