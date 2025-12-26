/*
Problem credits: https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/description/

You are given two arrays nums1 and nums2 consisting of positive integers.

You have to replace all the 0's in both arrays with strictly positive integers such that the sum of elements of both arrays becomes equal.

Return the minimum equal sum you can obtain, or -1 if it is impossible.

Solution:
    Pick sum of non zero elemets and noOFZeros in each array.

    If there are no zeros in both, then sum needed to be equal and return the sum

    If any of them have no zeros, its sum should be atleast other sum + zeros

    Else, max of min1 and min2
*/
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int zeros1 = 0, zeros2 = 0;

        for (int n : nums1) {
            if (n == 0) zeros1++;
            sum1 += n;
        }

        for (int n : nums2) {
            if (n == 0) zeros2++;
            sum2 += n;
        }

        if (zeros1 == 0 && zeros2 == 0) {
            return sum1 == sum2 ? sum1 : -1;
        }
        long long min1 = sum1 + zeros1, min2 = sum2 + zeros2;
        if (zeros1 == 0) {
            return min2 <= sum1 ? sum1 : -1;
        } else if (zeros2 == 0) {
            return min1 <= sum2 ? sum2 : -1;
        }
        return max(min1, min2);
    }
};