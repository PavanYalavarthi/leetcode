/*
Problem credits: https://leetcode.com/problems/next-permutation/

Given an array of integers nums, find the next permutation of nums.

Solution: Pick first element from end that is < next element.
And swap it with element just greater than it.

And now reverse i+1 to end.
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() - 1, i = n - 1;
        while ( i >= 0 && nums[i] >= nums[i+1]) i--;
        if (i != -1) {
            int j = n;
            while (nums[i] >= nums[j]) j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};