/*
Problem credits: https://leetcode.com/problems/number-of-provinces/

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

Solution:
    #components using DFS
*/
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