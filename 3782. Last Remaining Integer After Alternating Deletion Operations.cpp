/*
Problem credits: https://leetcode.com/problems/last-remaining-integer-after-alternating-deletion-operations/description/

You are given an integer n.

We write the integers from 1 to n in a sequence from left to right. Then, alternately apply the following two operations until only one integer remains, starting with operation 1:

Operation 1: Starting from the left, delete every second number.
Operation 2: Starting from the right, delete every second number.
Return the last remaining integer.

 
Solution:
    Similar to leetcode 390.

    Head moves if direction is from right and remaining is even

    And remianing is (remaining + 1) / 2
*/

#define ll long long
class Solution {
public:
    long long lastInteger(long long n) {
        ll head =1, step =1, remaining = n;
        bool isRight = false;

        while(remaining > 1) {
            if (isRight && ((remaining & 1) == 0) ) {
                head += step;
            }
            remaining = (remaining + 1) >> 1;
            step <<= 1;
            isRight = !isRight;
        }
        return head;
    }
};