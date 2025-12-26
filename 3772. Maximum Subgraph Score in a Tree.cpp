/*
Problem credits: https://leetcode.com/problems/maximum-subgraph-score-in-a-tree/description/

You are given an undirected tree with n nodes, numbered from 0 to n - 1. It is represented by a 2D integer array edges​​​​​​​ of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

You are also given an integer array good of length n, where good[i] is 1 if the ith node is good, and 0 if it is bad.

Define the score of a subgraph as the number of good nodes minus the number of bad nodes in that subgraph.

For each node i, find the maximum possible score among all connected subgraphs that contain node i.

Return an array of n integers where the ith element is the maximum score for node i.

A subgraph is a graph whose vertices and edges are subsets of the original graph.

A connected subgraph is a subgraph in which every pair of its vertices is reachable from one another using only its edges.

SOlution:
    DP on trees on max size of good subtree
*/

class Solution {
    vector<int>score, ans;
    vector<vector<int>> adj;
public:
    int dfs(int node, int par, vector<int>& good) {
        int curr = good[node];
        for(auto& child: adj[node]) {
            if (child != par) {
                curr += max(0, dfs(child, node, good));
            }
        }
        return score[node] = curr;
    }

    void dfs2(int node, int par) {
        ans[node] = score[node];
        for(int child: adj[node]) {
            if (child != par) {
                int child_score = score[child], par_score = score[node];
                score[node] -= max(0, score[child]);
                score[child] += max(0, score[node]);
                dfs2(child, node);
                score[node] = par_score, score[child] = child_score;
            }
        }
    }

    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        score.resize(n);
        ans.resize(n);
        adj.resize(n);
        for(auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for(int &g: good) {
            if (g == 0)
                g = -1;
        }
        dfs(0, -1, good);
        dfs2(0, -1);
        return ans;
    }
};