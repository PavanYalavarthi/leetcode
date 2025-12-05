class Solution {
    int components = 0;
public:
    int dfs(int node, int par, vector<int>gr[], vector<int>& values, int k) {
        long long sum = values[node] % k;
        for(int child: gr[node]) {
            if (child != par)
                sum = (sum + dfs(child, node, gr, values, k)) % k;
        }
        if (sum == 0) components++;
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int>gr[n];
        for(auto& edge: edges) {
            gr[edge[0]].push_back(edge[1]);
            gr[edge[1]].push_back(edge[0]);
        }
        dfs(0, -1, gr, values, k);
        return components;
    }
};