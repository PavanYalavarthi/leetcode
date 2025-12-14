/*
Problem credits: https://leetcode.com/problems/pacific-atlantic-water-flow/

There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

Solution: Do dfs on first and last,  rows and columns and add to ans if it is reachable from pacific and atlantic 
*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<bool>> pac, atl;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        pac = atl = vector<vector<bool>>(rows, vector<bool>(cols, false));
        for(int i = 0; i< rows; i++) {
            dfs(heights, pac, i, 0);
            dfs(heights, atl, i, cols -1);
        }
        for(int i = 0; i< cols; i++) {
            dfs(heights, pac, 0, i);
            dfs(heights, atl, rows - 1, i);
        }
        return ans;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>> & visited, int i, int j) {
        if (visited[i][j]) return;
        visited[i][j] = true;
        if(pac[i][j] && atl[i][j]) ans.push_back({i, j});
        int dir[] = {1, 0, -1, 0 , 1};
        for(int k =0; k < 4; k++) {
            int i1 = i + dir[k], j1 = j + dir[k + 1];
            if (i1 == -1 || i1 == heights.size() || j1 == -1 || j1 == heights[0].size() || heights[i][j] > heights[i1][j1]) continue;
            dfs(heights, visited, i1, j1);
        }
    }
};