/*
problem credits: https://leetcode.com/problems/number-of-islands/

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

Solution: Basic DFS
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i == -1 || i == grid.size() || j == -1 || j == grid[0].size() || grid[i][j] == '0') return;
        grid[i][j] = '0';
        int dir[] = {1, 0, -1, 0, 1};
        for(int k = 0; k < 4; k++)
            dfs(grid, i + dir[k], j + dir[k+1]);
    }
};