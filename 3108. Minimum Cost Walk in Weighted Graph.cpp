/*
problem credits: https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/description/

There is an undirected weighted graph with n vertices labeled from 0 to n - 1.

You are given the integer n and an array edges, where edges[i] = [ui, vi, wi] indicates that there is an edge between vertices ui and vi with a weight of wi.

A walk on a graph is a sequence of vertices and edges. The walk starts and ends with a vertex, and each edge connects the vertex that comes before it and the vertex that comes after it. It's important to note that a walk may visit the same edge or vertex more than once.

The cost of a walk starting at node u and ending at node v is defined as the bitwise AND of the weights of the edges traversed during the walk. In other words, if the sequence of edge weights encountered during the walk is w0, w1, w2, ..., wk, then the cost is calculated as w0 & w1 & w2 & ... & wk, where & denotes the bitwise AND operator.

You are also given a 2D array query, where query[i] = [si, ti]. For each query, you need to find the minimum cost of the walk starting at vertex si and ending at vertex ti. If there exists no such walk, the answer is -1.

Return the array answer, where answer[i] denotes the minimum cost of a walk for query i.


Solution:
    We need to take all the edges in respective component and and them to get minimum cost.
    
    Now, do dfs and add component. If both belongs to same component, min distance is and of the componet else -1
*/
class Solution {
    vector<int>component;
    vector<vector<pair<int, int>>>gr;
    int dfs(int node, int componentCnt) {
        component[node] = componentCnt;
        int currentCost = INT_MAX;
        for(auto& [child, w]: gr[node]) {
            currentCost &= w;
            if (component[child] == -1) {
                currentCost &= dfs(child, componentCnt);
            }
        }
        return currentCost;
    }
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        gr.assign(n, {});
        for(auto& edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            gr[u].push_back({v, w});
            gr[v].push_back({u, w}); 
        }
        component.assign(n, -1);
        vector<int>componentCost;
        int componentCnt = -1;
        for(int i =0; i < n; i++) {
            if (component[i] == -1) {
                componentCnt++;
                int cost = dfs(i, componentCnt);
                componentCost.push_back(cost);
            }
        }

        vector<int>ans(query.size());
        for(int i = 0; i< query.size(); i++) {
            int l = query[i][0], r = query[i][1];
            if (component[l] != component[r]) {
                ans[i] = -1;
            } else {
                ans[i] = componentCost[component[l]];
            }
        }
        return ans;
    }
};