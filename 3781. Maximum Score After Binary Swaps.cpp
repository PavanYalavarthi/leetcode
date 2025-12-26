/*

Problem. credits: https://leetcode.com/problems/maximum-score-after-binary-swaps/description/


You are given an integer array nums of length n and a binary string s of the same length.

Initially, your score is 0. Each index i where s[i] = '1' contributes nums[i] to the score.

You may perform any number of operations (including zero). In one operation, you may choose an index i such that 0 <= i < n - 1, where s[i] = '0', and s[i + 1] = '1', and swap these two characters.

Return an integer denoting the maximum possible score you can achieve.

Solution:
    We can only swap 1 to left, so pick max elementwhen s[i] is 1 from priority qiueue
*/

class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        int n = nums.size();
        priority_queue<int> pq;
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            pq.push(nums[i]);
            if (s[i] == '1'){
                ans += pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};