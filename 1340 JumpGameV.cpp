/*
Problem credits: https://leetcode.com/problems/jump-game-v/

Given an array of integers arr and an integer d. In one step you can jump from index i to index:

i + x where: i + x < arr.length and  0 < x <= d.
i - x where: i - x >= 0 and  0 < x <= d.
In addition, you can only jump from index i to index j if arr[i] > arr[j] and arr[i] > arr[k] for all indices k between i and j (More formally min(i, j) < k < max(i, j)).

You can choose any index of the array and start jumping. Return the maximum number of indices you can visit.

Notice that you can not jump outside of the array at any time.

Solution:
Use monotonic stack and add edges from i to all reachable vertices and find maximum depth
*/
class Solution {
public:
    int dfs(int node, vector<int> gr[], vector<int>& depth) {
        int& ans = depth[node];
        if (ans != 0) return ans;
        ans = 1;
        for(int child: gr[node]) {
            ans = max(ans, 1 + dfs(child, gr, depth));
        }
        return ans;
     }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int>gr[n];
        stack<int>stk;

        for(int i = 0; i < n; i++) {
            while(!stk.empty() && arr[stk.top()] < arr[i]) {
                if (i - stk.top() <= d) gr[i].push_back(stk.top());
                stk.pop();
            }
            stk.push(i);
        }
        while (!stk.empty()) stk.pop();
        for(int i = n-1; i >= 0; i--) {
            while(!stk.empty() && arr[stk.top()] < arr[i]) {
                if (stk.top() - i <= d) gr[i].push_back(stk.top());
                stk.pop();
            }
            stk.push(i);
        }
        vector<int>depth(n, 0);
        int ans = 0;
        for(int i =0; i< n; i++) {
            if (depth[i] == 0) {
                ans = max(ans, dfs(i, gr, depth));
            }
        }
        return ans;
    }
};