/*
Problem credits: https://leetcode.com/problems/remove-element/description/

Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.

Solution: Similar to 26, but condition is != val
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        for(int i =0 ;i<n;)
            if(nums[i] == val)
                swap(nums[i], nums[--n]);
            else i++;
        return n;
    }
};