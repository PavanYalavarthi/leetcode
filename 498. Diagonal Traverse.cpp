class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int row = 0, col = 0;
        bool isUpward = true;
        vector<int> ans(m * n);
        int index = 0;
        while(row < m && col < n) {
            ans[index++] = mat[row][col];
            int new_row = row + (isUpward ? -1 :1);
            int new_col = col + (isUpward ? 1 : -1);

            if (new_row < 0 || new_row == m || new_col < 0 || new_col == n) {
                if (isUpward) {
                    row += (col == n - 1 ? 1 : 0);
                    col += (col < n - 1 ? 1 : 0);
                } else {
                    col += (row == m - 1 ? 1 : 0);
                    row += (row < m - 1 ? 1 : 0);
                }
                isUpward = !isUpward;
            } else {
                row = new_row , col = new_col;
            }
        }
        return ans;
    }
};