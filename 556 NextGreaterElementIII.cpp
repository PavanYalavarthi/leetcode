/*
Problem credits: https://leetcode.com/problems/next-greater-element-iii/description/

Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1

Solution:
    Get next permuntation of the given integer. If it doesnt exist or >INT_MAx. return -1
*/
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i = s.length() - 2;
        while(i >= 0 && s[i] >= s[i + 1]) i--;
        if (i == -1) return -1;
        int j = s.length() - 1;
        while(s[j] <= s[i]) j--;
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
        long l =  stol(s);
        return l > INT_MAX ? - 1 : (int)l;
    }
};