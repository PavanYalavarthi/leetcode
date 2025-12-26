/*
problem credits: https://leetcode.com/problems/maximum-number-of-k-divisible-components/

There is an undirected tree with n nodes labeled from 0 to n - 1. You are given the integer n and a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

You are also given a 0-indexed integer array values of length n, where values[i] is the value associated with the ith node, and an integer k.

A valid split of the tree is obtained by removing any set of edges, possibly empty, from the tree such that the resulting components all have values that are divisible by k, where the value of a connected component is the sum of the values of its nodes.

Return the maximum number of components in any valid split.


Solution:
    Do dfs and return sum of the subtree to parent.

    And if sum is % k, increment component count.
*/
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