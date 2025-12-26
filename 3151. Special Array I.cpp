/*
problem credits: https://leetcode.com/problems/special-array-i/description/

An array is considered special if the parity of every pair of adjacent elements is different. In other words, one element in each pair must be even, and the other must be odd.

You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.

Solution:
    check for consective and if there are. of same parity, return false
    else true
*/
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
     for(int i = 0; i< nums.size()-1; i++) {
        if( ((nums[i] ^ nums[i+1]) & 1) == 0 )
            return false;
     }
     return true;   
    }
};