/*
Problem credits: https://leetcode.com/problems/subarray-product-less-than-k/

Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

Solution: Sliding window
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<2) return 0;
        int startIndex = 0, count = 0;
        for(int i = 0, product = 1; i<nums.size(); i++){
            product *= nums[i];
            while(startIndex <= i && product >= k) product /= nums[startIndex++];
            count += 1 + i - startIndex;
        }
        return count;
    }
};