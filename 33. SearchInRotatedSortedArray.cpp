/*
problem credits: https://leetcode.com/problems/search-in-rotated-sorted-array/

Given the array nums after the possible rotation of a sorted array and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

Solution:
    Consider it as 2 sorted sequence low .. i and i .. high, i is min value/
    ele >= [mid] => If a[low] <= target <= a[mid] => then high =- mid -1 else mid +1
    if a[mid] <= target <= a[high] => low = mid +1;
    else high = mid - 1;
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid, mid_ele;
        while (low <= high) {
            mid = (high + low) >> 1;
            mid_ele = nums[mid];
            if (mid_ele == target) return mid;
            if (int low_ele = nums[low]; mid_ele >= low_ele) {
                if (low_ele <= target && target <= mid_ele) high = mid - 1;
                else low = mid + 1;
            }
            else if (mid_ele < target && target <= nums[high]) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};