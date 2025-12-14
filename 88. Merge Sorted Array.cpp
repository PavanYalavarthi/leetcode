/*
problem credits: https://leetcode.com/problems/merge-sorted-array/

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.


Solution:
    basic merge logic
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        m--,n--;
        while( m>=0 && n>=0) {
            if(nums1[m] > nums2[n]) nums1[m + n + 2] = nums1[m--];
            else nums1[m + n + 2] = nums2[n--];
        }
        while(n >=0){
            nums1[m + n + 2] = nums2[n--];
        }
    }
};