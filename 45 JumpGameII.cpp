/*
Problem credits: https://leetcode.com/problems/jump-game-ii/

You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.


Solution: 
    Always keep max jump that can be made from current index.
    Once the curr_jump becomes 0, incremnt and take max jump that can be made
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        for(int i = 0, a = 0, b = 0; i < nums.size() - 1; i++, a--, b--) {
            b = max(b, nums[i]);
            if (a == 0) {
                ans++;
                a = b;
            }
        }
        return ans;
    }
};x