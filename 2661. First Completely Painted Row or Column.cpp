class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        unordered_map<int, pair<int, int>>mp;
        for(int i =0; i < rows; i++) 
            for(int j = 0; j < cols; j++)
                mp[mat[i][j]] = {i, j};
        vector<int> rowCount(rows, 0), colCount(cols, 0);
        for(int i =0; i <arr.size(); i++) {
            auto& [row, col] = mp[arr[i]];
            rowCount[row]++;
            colCount[col]++;
            if(rowCount[row] == cols || colCount[col] == rows) {
                return i;
            }
        }
        return -1;
    }
};