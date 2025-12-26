/*
Problem credits: https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/description/

You are given two integers num1 and num2.

In one operation, you can choose integer i in the range [0, 60] and subtract 2^i + num2 from num1.

Return the integer denoting the minimum number of operations needed to make num1 equal to 0.

If it is impossible to make num1 equal to 0, return -1.

SOlution:
  num1 - (2^i1 + num2) - (2 ^ i2 + num2) - .. (2^ik + nums2) = 0 => num1 - k * num2 = sum of 2^ij j 1.. k;
*/
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(long long k = 1; k <= 60; k++) {
            long long x = num1 - k * num2;
            if (x < k) break; // Worst case to pick all 1 for k, x should be atleast k
            if (k >= __builtin_popcountll(x)) return k; // If k is greater than or equal to bit count, then k is the ans
        }
        return -1;
    }
};