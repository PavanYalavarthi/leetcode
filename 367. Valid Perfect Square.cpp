/*
problem credits: https://leetcode.com/problems/valid-perfect-square/

Given a positive integer num, return true if num is a perfect square or false otherwise.

A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.

You must not use any built-in library function, such as sqrt.

Solution:
    use binary search to get proper sqyare root of the number
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        for(long long low = 1, high = num,mid; low<=high;){
            mid = low + (high - low) / 2;
            long long sq = mid * mid;
            if(sq == num) return true;
            else if(sq < num) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};