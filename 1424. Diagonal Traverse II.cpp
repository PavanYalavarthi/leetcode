/*
Problem credits: https://leetcode.com/problems/diagonal-traverse-ii/

Given a 2D integer array nums, return all elements of nums in diagonal order as shown in the below images.

Solution:
    we can observe (i+j) set needed to be in one set. and later push it in rever order in ans
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<int>> temp(2*n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < nums[i].size(); j++) {
                temp[i+j].push_back(nums[i][j]);
            }
        }
        vector<int>ans;
        for(int i =0 ; i< 2*n; i++) {
            ans.insert(ans.end(), temp[i].rbegin(), temp[i].rend());
        }
        return ans;
    }
};