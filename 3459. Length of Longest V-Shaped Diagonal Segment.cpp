class Solution {
    int dir[5] = {1, 1, -1, -1, 1};
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int memo[m][n][4][2];
        memset(memo, -1, sizeof(memo));
        function<int(int, int, int, bool, int)> dfs = [&] (int x, int y, int dir_index, bool turn, int target) -> int {
            int nx = x + dir[dir_index], ny = y + dir[dir_index + 1];
            if(nx < 0 || ny < 0 || nx == m || ny ==n || grid[nx][ny] != target) return 0;
            if(memo[nx][ny][dir_index][turn] != -1) return  memo[nx][ny][dir_index][turn];
            int &ans = memo[nx][ny][dir_index][turn];
            ans = dfs(nx, ny, dir_index, turn, 2 - target);
            if (turn) {
                ans = max(ans, dfs(nx, ny, (dir_index+1)%4, false, 2 - target));
            }
            return ++ans;
        };

        int res = 0;
        for(int i =0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    for(int k = 0; k< 4; k++) {
                        res = max(res, dfs(i, j, k, true, 2) + 1);
                    }
                }
            }
        }
        return res;
    }
};