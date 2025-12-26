/*
problem credits: https://leetcode.com/problems/total-sum-of-interaction-cost-in-tree-groups/description/

You are given an integer n and an undirected tree with n nodes numbered from 0 to n - 1. This is represented by a 2D array edges of length n - 1, where edges[i] = [ui, vi] indicates an undirected edge between nodes ui and vi.

You are also given an integer array group of length n, where group[i] denotes the group label assigned to node i.

Two nodes u and v are considered part of the same group if group[u] == group[v].
The interaction cost between u and v is defined as the number of edges on the unique path connecting them in the tree.
Return an integer denoting the sum of interaction costs over all unordered pairs (u, v) with u != v such that group[u] == group[v].


Solution:
    We need to see every edge contributes to cnt * (groupFreq - cnt)

    So applying the same for every subtree
*/

class Solution {
    vector<int>groupFreq;
    vector<vector<int>>adj;
    long long ans = 0;
public:
    long long dfs(int node, int parent, int grp, vector<int>& group) {
        int cnt = (group[node] == grp);

        for(int child: adj[node]) {
            if (child != parent) {
                cnt += dfs(child, node, grp, group);
            }
        }
        ans += 1LL * cnt * (groupFreq[grp] - cnt);
        return cnt;
    }

    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        adj.resize(n);
        for(auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        groupFreq.assign(21, 0);
        for(int g: group) {
            groupFreq[g]++;
        }

        for(int g = 1; g <= 20; g++) {
            if (groupFreq[g]) {
                dfs(0, -1, g, group);
            }
        }
        return ans;
    }
};