class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int min_i = INT_MAX , max_i = INT_MIN, min_j = INT_MAX, max_j = INT_MIN;
        for (int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    min_i = min(min_i, i);
                    min_j = min(min_j, j);
                    max_i = max(max_i, i);
                    max_j = max(max_j, j);
                }
            }
        }
        return (max_i - min_i + 1) * (max_j - min_j + 1);
    }
};