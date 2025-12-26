/*
problem credits: https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/description/

You are given an integer array nums and an integer k. You can perform the following operation any number of times:

Select an index i and replace nums[i] with nums[i] - 1.
Return the minimum number of operations required to make the sum of the array divisible by k.

Solution:
    do total sum % k it gives how many -1 needed to be performed
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for (int num: nums) {
            sum = (sum + num)%k;
        }
        return sum;
    }
};