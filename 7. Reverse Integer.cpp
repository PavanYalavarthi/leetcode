/*
Problem credits: https://leetcode.com/problems/reverse-integer/description/

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Solution:
Reversing anumber, but, just make sure before multiplying ans withj 10 for next number, where it lies in the range
*/

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x) {
            if (ans > INT_MAX/10 || ans < INT_MIN/10) return 0;
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
};