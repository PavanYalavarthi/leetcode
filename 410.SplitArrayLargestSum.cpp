/*
Problem credits: https://leetcode.com/problems/split-array-largest-sum/description/

Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

Solution: Paritions <= k with max_sum is monotonic function. SO applying binary search on it
*/
class Solution {
public:
    bool isPossible(vector<int>& nums, int max_sum, int k) {
        int sum = 0, count = 1;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > max_sum) {
                count++;
                if (count > k) break;
                sum = nums[i];
            }
        }
        return (count <= k);
    }
    int splitArray(vector<int>& nums, int k) {
        int start = 0, end = 0, ans;
        for(int i = 0; i < nums.size(); i++) {
            start = max(start, nums[i]);
            end += nums[i];
        }
        while (start <= end) {
            int mid = start + (end- start) / 2;
            if (isPossible(nums, mid, k)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};