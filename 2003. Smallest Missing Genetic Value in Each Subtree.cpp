/*
problem credits: https://leetcode.com/problems/smallest-missing-genetic-value-in-each-subtree/description/

There is a family tree rooted at 0 consisting of n nodes numbered 0 to n - 1. You are given a 0-indexed integer array parents, where parents[i] is the parent for node i. Since node 0 is the root, parents[0] == -1.

There are 10^5 genetic values, each represented by an integer in the inclusive range [1, 105]. You are given a 0-indexed integer array nums, where nums[i] is a distinct genetic value for node i.

Return an array ans of length n where ans[i] is the smallest genetic value that is missing from the subtree rooted at node i.

The subtree rooted at a node x contains node x and all of its descendant nodes.

SOlution:
    only node with val 1 and its ancestors value changes, So, we do dfs on those nodes and pick the max val that is not present
*/

class Solution {
    unordered_set<int> visited;
    vector<vector<int>>adj;
public:
    void dfs(int node, vector<int>& nums) {
        if(visited.count(nums[node])) return;
        visited.insert(nums[node]);
        for (int child: adj[node]) {
            dfs(child, nums);
        }
    }
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size();
        vector<int>ans(n, 1);
        int indexOf1 = -1;
        for(int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                indexOf1 = i;
                break;
            }
        }
        adj.resize(n);
        for(int i = 1; i <n ;i++) adj[parents[i]].push_back(i);
        // Checking the minimum value missing
        int missingValue = 2;
        int node = indexOf1;
        while(node != -1) {
            dfs(node, nums);
            while(visited.count(missingValue)) missingValue++;
            ans[node] = missingValue;
            node = parents[node];
        }
        return ans;
    }
};