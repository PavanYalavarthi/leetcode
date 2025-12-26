/*
problem credits: https://leetcode.com/problems/minimize-xor/description/

Given two positive integers num1 and num2, find the positive integer x such that:

x has the same number of set bits as num2, and
The value x XOR num1 is minimal.
Note that XOR is the bitwise XOR operation.

Return the integer x. The test cases are generated such that x is uniquely determined.

The number of set bits of an integer is the number of 1's in its binary representation.

Solution:
    Self explanatory
*/
class Solution {
public:
    int removeBits(int num, int noOfBits) {
        while(noOfBits--) {
            num &= (num - 1);
        }
        return num;
    }

    int addBits(int num, int noOfBits) {
        int bitPos = 0;
        while(noOfBits--) {
            while (num & (1 << bitPos)) bitPos++;
            num |= (1 << bitPos);
        }
        return num;
    }

    int minimizeXor(int num1, int num2) {
        int bitsOfNum1 = __builtin_popcount(num1), bitsOfNum2 =  __builtin_popcount(num2);
        if (bitsOfNum1 == bitsOfNum2) return num1;
        if (bitsOfNum1  > bitsOfNum2) return removeBits(num1, bitsOfNum1 - bitsOfNum2);
        return addBits(num1, bitsOfNum2 - bitsOfNum1);
    }
};