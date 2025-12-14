/*
problem credits: https://leetcode.com/problems/product-of-array-except-self/

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].


Solution:
    Keep counting #zeros and product of remaining elements
    If #zeros > 1, return vector with 0 s

    Else, if element is 0, add whole product, else whole product / ele
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, numOfZeros = 0;
        for(int num: nums) {
            if (num == 0) numOfZeros++;
            else product *= num;
        }
        if (numOfZeros > 1) return vector<int>(nums.size(), 0);
        for (int & num: nums) {
            if (num == 0) num = product;
            else if (numOfZeros == 1) num = 0;
            else num = product / num;
        }
        return nums;
    }
};