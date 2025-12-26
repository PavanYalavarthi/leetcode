/*
Problem credits: https://leetcode.com/problems/count-submatrices-with-all-ones/description/

Given an m x n binary matrix mat, return the number of submatrices that have all ones.

SOlution: Use histogram for each row, and pop heights that are >= curr height, now #rectangles = curr_height * (i - stack.top().index) + ans at stack.top
*/
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat[0].size();
        vector<int>height(n, 0);
        int ans= 0;
        for(auto& row: mat) {
            for(int i = 0; i < n; i++) {
                height[i] = (row[i] == 0) ? 0 : height[i]+1;
            }
            stack<vector<int>>stk;
            stk.push({-1, -1, 0});
            for(int i = 0; i < n ; i++) {
                int h = height[i];
                while (stk.top().at(1) >= h) stk.pop();
                int cur_ans = (i - stk.top().at(0)) * h + stk.top().at(2);
                ans += cur_ans;
                stk.push({i, h, cur_ans});
            }
        }
        return ans;
    }
};