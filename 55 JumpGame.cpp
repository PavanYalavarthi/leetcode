/*
Prpblem credits: https://leetcode.com/problems/jump-game/description/

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Solution:
    Keep track on max index that can be reached. If cur_index > max_index that we cant be reached there.
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_index = 0, n = nums.size();
        for(int i = 0; i<n; i++) {
            if (i > max_index) return false;
            max_index = max(max_index, i + nums[i]);
            if (max_index >= n -1) return true;
        }
        return true;
    }
};