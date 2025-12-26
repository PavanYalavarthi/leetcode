/*
Problem credits: https://leetcode.com/problems/count-partitions-with-max-min-difference-at-most-k/

You are given an integer array nums and an integer k. Your task is to partition nums into one or more non-empty contiguous segments such that in each segment, the difference between its maximum and minimum elements is at most k.

Return the total number of ways to partition nums under this condition.

Since the answer may be too large, return it modulo 109 + 7.

Solution:
    Use monotonic queue to get max and min in the range and move left pointer till max- min <= k,

    And dp[left] + .. dp[right] = dp[right + 1]
*/
#define MOD 1000000007
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>dp(n+1);
        dp[0] = 1;
        deque<int>minQ, maxQ;
        int sum = 1;
        for(int i = 0, j = 0; j<n; j++) {
            while (!maxQ.empty() && nums[maxQ.back()] < nums[j]) {
                maxQ.pop_back();
            }
            maxQ.push_back(j);
            while (!minQ.empty() && nums[minQ.back()] > nums[j]) {
                minQ.pop_back();
            }
            minQ.push_back(j);

            while (nums[maxQ.front()] - nums[minQ.front()] > k) {
                sum = (sum - dp[i++] + MOD) % MOD;
                if (minQ.front() < i) minQ.pop_front();
                if (maxQ.front() < i) maxQ.pop_front();
            }
            dp[j+1] = sum;
            sum = (sum + dp[j+1]) % MOD;
        }
        return dp[n];

    }
};