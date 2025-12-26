/*
Problem credits: https://leetcode.com/problems/absolute-difference-between-maximum-and-minimum-k-elements/description/

You are given an integer array nums and an integer k.

Find the absolute difference between:

the sum of the k largest elements in the array; and
the sum of the k smallest elements in the array.
Return an integer denoting this difference.

Solution:
    Sort and find diff between k largest and smallest elements;
*/

class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size();
        for(int i = 0; i <k ; i++) {
            ans += nums[n - 1 - i] - nums[i];
        }
        return ans;
    }
};