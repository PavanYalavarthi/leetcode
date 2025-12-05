class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0, n = isConnected.size();
        vector<bool>visited(n , false);
        for(int i = 0; i < isConnected.size(); i++) {
            if (!visited[i]) {
                count++;
                dfs(isConnected, i, visited);
            }
        }
        return count;
    }

    void dfs(vector<vector<int>>& isConnected, int node,  vector<bool> &visited) {
        visited[node] = true;
        for(int j = 0; j< isConnected.size(); j++){
            if (!visited[j] && isConnected[node][j]) dfs(isConnected, j, visited);
        }
    }
};