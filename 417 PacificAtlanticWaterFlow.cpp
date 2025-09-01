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