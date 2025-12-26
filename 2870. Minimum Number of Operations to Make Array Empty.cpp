/*
Problem credits: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/

You are given a 0-indexed array nums consisting of positive integers.

There are two types of operations that you can apply on the array any number of times:

Choose two elements with equal values and delete them from the array.
Choose three elements with equal values and delete them from the array.
Return the minimum number of operations required to make the array empty, or -1 if it is not possible.

Solution:
    Take freq of elements. If freq is 1, we cant delete it
    else we pick 3 elements and delete and if still present we increment by 1
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        for(int num : nums) mp[num]++;
        int count = 0;
        for(auto &[key, val] : mp){
            if(val == 1) return -1;
            count += val/3;
            if(val%3) count++;
        }
        return count;
    }
};