/*
Problem credits: https://leetcode.com/problems/single-element-in-a-sorted-array/description/

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.


Solution: 
    use binary search on condition that single element will not be equal to next element and it will be on even index(zero based)
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = (l + r) / 2;
            if (mid % 2 == 1) {
                mid--;
            }
            if (nums[mid] == nums[mid +1]) { // if even place == odd place, all elements are even times.
                l = mid + 2;
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
};