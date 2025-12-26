/*
problem credits: https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment/

You are given a 2D integer matrix grid of size n x m, where each element is either 0, 1, or 2.

A V-shaped diagonal segment is defined as:

The segment starts with 1.
The subsequent elements follow this infinite sequence: 2, 0, 2, 0, ....
The segment:
Starts along a diagonal direction (top-left to bottom-right, bottom-right to top-left, top-right to bottom-left, or bottom-left to top-right).
Continues the sequence in the same diagonal direction.
Makes at most one clockwise 90-degree turn to another diagonal direction while maintaining the sequence.
Return the length of the longest V-shaped diagonal segment. If no valid segment exists, return 0.

 
SOlution:
    Do dfs with i, j , direction and turn dp to save the longest v
*/
class Solution {
    int dp[501][501][4][2], m, n;
    int dir[5] = {1, 1, -1, -1, 1};
    int dfs (int i, int j, int dir_index, bool turn, int target, vector<vector<int>>& grid) {
        int new_i = i + dir[dir_index], new_j = j + dir[dir_index + 1];
        if (new_i == -1 || new_i == m || new_j == -1 || new_j == n || grid[new_i][new_j] != target) {
            return 0;
        } 
        int& ans =  dp[new_i][new_j][dir_index][turn];
        if (ans != -1) return ans;
        ans = dfs(new_i, new_j, dir_index, turn, 2 -target, grid);
        if (turn) {
            ans = max(ans, dfs(new_i, new_j, (dir_index + 1) % 4, false, 2 - target, grid));
        }
        return ++ans;
    }
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        int res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for(int k = 0; k < 4 ; k++)
                        res= max(res, 1 + dfs(i, j, k, true, 2, grid));
                }
            }
        }
        return res;
    }
};