/*
Problem credits: https://leetcode.com/problems/rotate-array/

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Solution: initally convert k to k % n

And now, reverse 1.. n-k, n-k+1, n and then 1 .. n
*/
class Solution {
public:
    void reverse(vector<int>&nums, int start, int end){
        while(start < end) swap(nums[start++], nums[end--]);
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if(k==0) return;
        if(n==1) return;
        reverse(nums, 0, n-k-1);
        reverse(nums, n-k,n-1);
        reverse(nums, 0, n-1);
    }
};