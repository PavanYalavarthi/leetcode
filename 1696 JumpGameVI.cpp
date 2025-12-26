/*
Problem credits: https://leetcode.com/problems/jump-game-vi/description/

You are given a 0-indexed integer array nums and an integer k.

You are initially standing at index 0. In one move, you can jump at most k steps forward without going outside the boundaries of the array. That is, you can jump from index i to any index in the range [i + 1, min(n - 1, i + k)] inclusive.

You want to reach the last index of the array (index n - 1). Your score is the sum of all nums[j] for each index j you visited in the array.

Return the maximum score you can get.

SOlution:
    use monotonic queue for getting max of last k elements. and keep adding it to num[i]. 
*/
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int>dq;
        dq.push_back(0);
        for (int i =1; i < n; i++) {
            nums[i] += nums[dq.front()];
            if (i - dq.front() >= k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
        }
        return nums[n-1];
    }
};