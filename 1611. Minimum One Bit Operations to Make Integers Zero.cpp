/*
problem credits: https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/description/

Given an integer n, you must transform it into 0 using the following operations any number of times:

Change the rightmost (0th) bit in the binary representation of n.
Change the ith bit in the binary representation of n if the (i-1)th bit is set to 1 and the (i-2)th through 0th bits are set to 0.
Return the minimum number of operations to transform n into 0.

Solution:
    Its similar ot gray code,
     in gray code, to get previous number
        if even parity, flip lsb
        if odd parity, flip bit to left of lowest set bit.
    So, as we need to move to zero, we need to do n greay code steps or equivalent binary code steps

    So, it come to one, we needed to know, which binary number this gray code represent
*/
class Solution {
public:
    int minimumOneBitOperations(int n) {
        n ^= n >>16;
        n ^= n >> 8;
        n ^= n >> 4;
        n ^= n >> 2;
        n ^= n>>1;
        return n;
    }
};