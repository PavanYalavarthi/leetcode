/*
Problem credits: https://leetcode.com/problems/palindrome-number/description/

Problem description: Given an integer x, return true if x is a palindrome, and false otherwise.

Solution: reverse the number and compare it with actual. Filter negative initially.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if ( x < 0) return false;
        long long reversed = 0, temp = x;
        while(temp) {
            reversed = reversed * 10 + temp % 10;
            temp /= 10;
        }
        return x == reversed;
    }
};