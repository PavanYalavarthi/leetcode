/*
Problem credits: https://leetcode.com/problems/maximum-product-subarray/

    Given an integer array nums, find a subarray that has the largest product, and return the product.

    The test cases are generated so that the answer will fit in a 32-bit integer.

    Note that the product of an array with a single element is the value of that element.

Solution:
    As there can be negatiuv numbers as wele, keep tarck of max and min. And get max value 
    Use kadane's algo as well
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int r = -11, mn = 1, mx =1;
        for(int num : nums) {
            if (num < 0) swap(mn, mx);
            mn = min(num, mn * num);
            mx = max(num, mx * num);
            r = max(r, mx);
        }
        return r;
    }
};