/*
problem credits: https://leetcode.com/problems/count-array-pairs-divisible-by-k/description/

Given a 0-indexed integer array nums of length n and an integer k, return the number of pairs (i, j) such that:

0 <= i < j <= n - 1 and
nums[i] * nums[j] is divisible by k.

Solution:   (a * b) % k ==0 => gcd(a, k) * gcd(b, k) == 0
*/
class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long ans = 0;
        for(int num: nums) {
            long long curGcd = __gcd(num, k);
            for(auto& [gcd, freq] : mp) {
                if (gcd * curGcd % k == 0) {
                    ans += freq;
                }
            }
            mp[curGcd]++;
        }
        return ans;
    }
};