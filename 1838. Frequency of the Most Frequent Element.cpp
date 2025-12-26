/*
Problem credits: https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/

The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.

SOlution:
    Use sliding window with condition (r - l + 1) * nums[r] - sum > k
*/
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        long long sum = 0;
        for(int l = 0, r = 0; r < nums.size(); r++) {
            sum += nums[r];
            while ((r - l +1) * (long long)nums[r] - sum > k) {
                sum -= nums[l++];
            }
            ans = max(ans, r - l +1);
        }
        return ans;
    }
};