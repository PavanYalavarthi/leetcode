/*
problem credits: https://leetcode.com/problems/count-partitions-with-even-sum-difference/description/

You are given an integer array nums of length n.

A partition is defined as an index i where 0 <= i < n - 1, splitting the array into two non-empty subarrays such that:

Left subarray contains indices [0, i].
Right subarray contains indices [i + 1, n - 1].
Return the number of partitions where the difference between the sum of the left and right subarrays is even.


Solution:
    If total sum is even, we can split array into odd , odd or even even

    Else opposite parity

    So, check whether total sum is even, if yes return n-1 else 0
*/
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0, ans = 0, total_sum = 0;
        for(int num: nums) total_sum = (total_sum + num) % 2;
        return (total_sum  == 0) ? nums.size() -1 : 0;
    }
};