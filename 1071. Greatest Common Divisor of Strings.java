/*
Problem credits: https://leetcode.com/problems/greatest-common-divisor-of-strings/

For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

Solution:
    to have GCD, we need to have s1 +s2 == s2 + s1, now pick substring from 0 to gcd(s1.len(), s2.len())
*/
class Solution {
    public int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
    public String gcdOfStrings(String str1, String str2) {
        if( (str1 + str2).equals(str2 + str1)) 
            return str1.substring(0, gcd(str1.length(), str2.length()));
        return "";
    }
}