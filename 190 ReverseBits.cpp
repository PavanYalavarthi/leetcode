/*
Problem credits: https://leetcode.com/problems/reverse-bits/

Reverse bits of a given 32 bits signed integer.

Solution: self explainatory
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        for(int i = 0; i < 32; i++) {
            res = (res << 1) | (n & 1);
            n >>= 1;
        }
        return res;
    }
};