/*
Problem credits: https://leetcode.com/problems/largest-3-same-digit-number-in-string/description/

You are given a string num representing a large integer. An integer is good if it meets the following conditions:

It is a substring of num with length 3.
It consists of only one unique digit.
Return the maximum good integer as a string or an empty string "" if no such integer exists.

Note:

A substring is a contiguous sequence of characters within a string.
There may be leading zeroes in num or a good integer.
 

Solution:
    keep incremnting on seeing same char on prev index and get max number
*/
class Solution {
public:
    string largestGoodInteger(string num) {
        char ans = ' ';
        char prev = 'a';
        int cnt = 0;
        for(char c: num) {
            if (c == prev) {
                cnt++;
                if (cnt == 3) {
                    if (ans < c) {
                        ans = c;
                    }
                }
            } else {
                cnt = 1;
            }
            prev = c;
        }
        return (ans == ' ' ? "" : string(3, ans));
    }
};