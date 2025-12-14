/*
problem credits: https://leetcode.com/problems/find-peak-element/

A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

Solution:
    each local maximum is one valid peak. So, find one of those peaks with binary search
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid; 
        while (low < high) {
            mid = (low + high) / 2;
            (nums[mid] > nums[mid + 1]) ? (high = mid) : (low = mid + 1);
        }
        return low;
    }
};