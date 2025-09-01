class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int M = mat.size(), N = mat[0].size();
        vector<vector<int>> prefixSum(M + 1, vector<int>(N+1, 0));
        for(int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                prefixSum[i][j] = mat[i-1][j-1] + prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1];
            }
        }

        vector<vector<int>> ans(M, vector<int>(N));
        for(int i = 0; i< M; i++) {
            for(int j = 0; j< N; j++) {
                int r1 = max(0, i - k), c1 = max(0, j - k), r2 = min(M, i + k + 1), c2 = min(N, j + k +1);
                ans[i][j] = prefixSum[r2][c2] - prefixSum[r1][c2] - prefixSum[r2][c1] + prefixSum[r1][c1];
            }
        }
        return ans;
    }
};