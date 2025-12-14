/*
Problem credits: https://leetcode.com/problems/01-matrix/

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

Solution:
    multi source bfs + Shortest path using bfs
 */
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int m = mat.size(), n= mat[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j< n; j++) {
                if (mat[i][j] == 0) {
                    q.emplace(i, j);
                } else mat[i][j] = -1;
            }
        int dir[] = {1, 0, -1, 0, 1};
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nr = r + dir[i], nc = c + dir[i+1];
                if (nr < 0 || nc < 0 || nr == m || nc == n || mat[nr][nc] != -1) continue;
                mat[nr][nc] = mat[r][c] + 1;
                q.emplace(nr, nc);
            }
        }
        return mat;
    }
};