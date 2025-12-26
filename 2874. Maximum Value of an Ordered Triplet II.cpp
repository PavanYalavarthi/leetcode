/*
Problem credits: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/description/

You are given a 0-indexed integer array nums.

Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all such triplets have a negative value, return 0.

The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].

Solution:
  Keep track of arr[i] and max value of (maxi - num), and muliply with arr[k] (same as 2873 with strict constraint)
*/
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long result = 0;
        int maxij = 0, maxi = 0;
        for (int num : nums) {
            result = max(result, 1LL * maxij * num);
            maxij = max(maxij, maxi - num);
            maxi = max(maxi, num);
        }
        return result;
    }
};