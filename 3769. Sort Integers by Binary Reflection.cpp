/*
Problem credits: https://leetcode.com/problems/sort-integers-by-binary-reflection/description/

You are given an integer array nums.

The binary reflection of a positive integer is defined as the number obtained by reversing the order of its binary digits (ignoring any leading zeros) and interpreting the resulting binary number as a decimal.

Sort the array in ascending order based on the binary reflection of each element. If two different numbers have the same binary reflection, the smaller original number should appear first.

Return the resulting sorted array.

Solution:
    Sort based on reversed Binary.
*/

class Solution {
    int reverseBinary(int num) {
        int ans = 0;
        while(num) {
            ans = (ans << 1) | (num&1);
            num >>= 1;
        }
        return ans;
    }
public:
    vector<int> sortByReflection(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            int a1 = reverseBinary(a), b1 = reverseBinary(b);
            return (a1 == b1) ? a < b : a1 < b1;
        });
        return nums;
    }
};