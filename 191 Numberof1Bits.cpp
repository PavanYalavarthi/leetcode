/*
problem credits: https://leetcode.com/problems/number-of-1-bits/

Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

Solution:
    n & (n-1) unsets last set bit. So looping till it is made
*/
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n) {
            count++;
            n &= (n - 1);
        }
        return count;
    }
};