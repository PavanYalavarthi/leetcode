/*
Problem credits: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Solution:
    binary search in array, and use flag whether ot move to left or right post element is found
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       int left = binary_search(nums, target, true);
       if(left == -1) return { -1, -1 };
       if(left == nums.size() - 1 || nums[left] != nums[left + 1] ) return {left, left};
       else return {left, binary_search(nums, target, false)};
    }
    
    int binary_search(vector<int>& nums, int target, bool doSearchLeft) {
        int left = 0, right = nums.size() - 1, mid, ans = -1;
        while(left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else {
                ans = mid;
                if (doSearchLeft) right = mid - 1;
                else left = mid + 1;
            }
        }
        return ans;
    }
};