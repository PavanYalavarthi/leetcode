/*
    Problem credits: https://leetcode.com/problems/count-number-of-nice-subarrays/

    Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

    Return the number of nice sub-arrays.

    Solution:
        Keep #odd count elements and use hashing to find number of subarrys with k odds
*/
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int ans = 0;
        for(int i = 0, oddCount; i < n; i++) {
            oddCount += nums[i] % 2;
            if (mp.count(oddCount - k)) {
                ans += mp[oddCount - k];
            }
            mp[oddCount]++;
        }
        return ans;
    }
};