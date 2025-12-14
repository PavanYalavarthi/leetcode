/*
Problem credits: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

Solution:
    As array is definely rotated,
        if arr[mid] < last ele, mid will be in left part
        else right part
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, last_ele = nums.back(), mid;
        while (low < high) {
            mid = (low + high) >> 1;
            if (nums[mid] < last_ele) high = mid;
            else low = mid + 1;
        }
        return nums[low];
    }
};