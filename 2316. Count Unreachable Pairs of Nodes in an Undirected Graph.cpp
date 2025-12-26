/*
Problem credits: https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/

You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

Return the number of pairs of different nodes that are unreachable from each other.

Solution:
    use DSU to find #unconnected pairs
*/
struct DSU {
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n, 1);
    }
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int x, int y) {
        int parX = find(x), parY = find(y);
        if(parX == parY) return;
        if(size[parX] < size[parY]) swap(parX, parY);
        parent[parY] = parX;
        size[parX] += size[parY];
    }
 };

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(const auto&e : edges) dsu.unite(e[0], e[1]);
        long res = 0, total = 0;
        for(int i=0;i<n;i++) {
            if (dsu.find(i) == i) {
                res += dsu.size[i] * total;
                total += dsu.size[i];
            }
        }
        return res;
    }
};