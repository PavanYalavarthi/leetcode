/*
Problem credits: https://leetcode.com/problems/three-consecutive-odds/

Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.

Solution: keep counter of number of consective odds, if counter hit 3 return true
*/
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int32_t count = 0;
        for(int num : arr) {
            if (num & 1) {
                count++;
                if (count == 3) return true;
            } 
            else count = 0;
        }
        return false;
    }
};