/*
problem credits: https://leetcode.com/problems/binary-subarrays-with-sum/description/

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

Solution:
    prefix sum hashing logic
*/
class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        HashMap<Integer, Integer> hm = new HashMap<>();
        hm.put(0,1);
        int prefixSum = 0, result =0;
        for(int i: nums) {
            prefixSum += i;
            result += hm.getOrDefault(prefixSum - goal, 0);
            hm.put(prefixSum, hm.getOrDefault(prefixSum,0) + 1);
        }
        return result;
    }
}