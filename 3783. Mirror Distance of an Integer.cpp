/*
Problem credits: https://leetcode.com/problems/mirror-distance-of-an-integer/

You are given an integer n.

Define its mirror distance as: abs(n - reverse(n) where reverse(n) is the integer formed by reversing the digits of n.

Return an integer denoting the mirror distance of n.

abs(x) denotes the absolute value of x.


Solution: 
    reverse the number and find absolute differnce of num with it
*/
class Solution {
public:
    int mirrorDistance(int n) {
        int temp = n, ans = 0;
        while(temp) {
            ans = ans * 10 + temp% 10;
            temp /= 10;
        }
        return abs(n - ans);
    }
};