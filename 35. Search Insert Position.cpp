/*
Problem credits: https://leetcode.com/problems/search-insert-position/description/

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Solution: binary search template
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        for(int h = nums.size() - 1; l<= h; ) {
            int mid = (l + h) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) h = mid -1;
            else l = mid + 1;
        }
        return l;
        
    }
};