/*
Problem credits: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/description/

Given an integer num, return the number of steps to reduce it to zero.

In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.

 
SOlution:
    Keep incrementing ans for each operation
*/
class Solution {
public:
    int numberOfSteps(int num) {
        int ans = 0;
        while(num) {
            if (num & 1) num-=1;
            else num >>=1;
            ans++;
        }
        return ans;
    }
};