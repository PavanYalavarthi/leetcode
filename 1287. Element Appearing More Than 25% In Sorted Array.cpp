/*
Problem credits: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/description/

Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.

Solution:
    from 0, n/4, 2n/4, 3n/4 check whether the range of the given element is > n/4, if yes, return it
*/
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n; i+= n/4) {
            auto [lb, up] = equal_range(arr.begin(), arr.end(), arr[i]);
            if (up - lb > n/4) {
                return arr[i];
            }
        }
        return -1;
    }
};