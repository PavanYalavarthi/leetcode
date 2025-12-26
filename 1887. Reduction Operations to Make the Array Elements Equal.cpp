/*
Problem credits: https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/description/

Given an integer array nums, your goal is to make all elements in nums equal. To complete one operation, follow these steps:

Find the largest value in nums. Let its index be i (0-indexed) and its value be largest. If there are multiple elements with the largest value, pick the smallest i.
Find the next largest value in nums strictly smaller than largest. Let its value be nextLargest.
Reduce nums[i] to nextLargest.
Return the number of operations to make all elements in nums equal.

Solution:
    We needed to move all bigger numbers to smaller numbers finally to the smallest number
*/
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int, int>mp;
        for(int num: nums) mp[num]++;
        int n = nums.size(), ans = 0;
        for(auto [key, freq]: mp) {
            ans += (n -= freq);
        }
        return ans;
    }
};