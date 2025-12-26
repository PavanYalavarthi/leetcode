/*
Problem credits: https://leetcode.com/problems/calculate-money-in-leetcode-bank/description/

Hercy wants to save money for his first car. He puts money in the Leetcode bank every day.

He starts by putting in $1 on Monday, the first day. Every day from Tuesday to Sunday, he will put in $1 more than the day before. On every subsequent Monday, he will put in $1 more than the previous Monday.

Given n, return the total amount of money he will have in the Leetcode bank at the end of the nth day.

Solution:
    self explanatory
*/
class Solution {
public:
    int totalMoney(int n) {
        int week = n / 7;
        int sum = week * 28 + 7 * (week * (week-1))/2;
        if( n % 7) {
            int rem = n % 7;
            sum += rem * (2 * week + rem  + 1) / 2;
        } 
        return sum;
    }
};