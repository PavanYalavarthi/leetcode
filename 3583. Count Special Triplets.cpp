/*
Problem credits: https://leetcode.com/problems/count-special-triplets/description/

You are given an integer array nums.

A special triplet is defined as a triplet of indices (i, j, k) such that:

0 <= i < j < k < n, where n = nums.length
nums[i] == nums[j] * 2
nums[k] == nums[j] * 2
Return the total number of special triplets in the array.

Since the answer may be large, return it modulo 109 + 7.

Solution:
    Keep freq from right and left and treat current element as j and see #ele to left = 2*a[j] and towards right
*/

const int MOD = 1e9 + 7;
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;
        unordered_map<int, int> r, l;
        for (int val : nums) {
            r[val]++;
        }

        for (int j = 0; j < n; ++j) {
            int mid = nums[j];
            r[mid]--; 
            int left = l[2 * mid];
            int right = r[2 * mid];
            result = (result + 1LL * left * right) % MOD;
            l[mid]++;
        }

        return result;
    }
};