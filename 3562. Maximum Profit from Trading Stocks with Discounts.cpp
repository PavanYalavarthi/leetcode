/*
Problem credits: https://leetcode.com/problems/maximum-profit-from-trading-stocks-with-discounts/description/

You are given an integer n, representing the number of employees in a company. Each employee is assigned a unique ID from 1 to n, and employee 1 is the CEO. You are given two 1-based integer arrays, present and future, each of length n, where:

present[i] represents the current price at which the ith employee can buy a stock today.
future[i] represents the expected price at which the ith employee can sell the stock tomorrow.
The company's hierarchy is represented by a 2D integer array hierarchy, where hierarchy[i] = [ui, vi] means that employee ui is the direct boss of employee vi.

Additionally, you have an integer budget representing the total funds available for investment.

However, the company has a discount policy: if an employee's direct boss purchases their own stock, then the employee can buy their stock at half the original price (floor(present[v] / 2)).

Return the maximum profit that can be achieved without exceeding the given budget.

Solution:
    Create tree and get dfs of children, its 0/1 knapsack for the child nodes.
*/

class Solution {
    vector<vector<int>> adj;
    int b;
public:
    // pair.first = dp1 (discount available for this subtree), pair.second = dp0 (no discount)
    pair<vector<int>, vector<int>> dfs(int node, vector<int>& present, vector<int>& future) {
        // Initialize with 0. These store the accumulated profit from children.
        vector<int> taken(b + 1, 0), notTaken(b + 1, 0);

        for(int child : adj[node]) {
            auto [childDp1, childDp0] = dfs(child, present, future);

            // Knapsack combination
            for(int i = b; i >= 0; i--) {
                for(int j = 0; j <= i; j++) {
                    // If this node is taken, children can use their discounted prices (childDp1)
                    taken[i] = max(taken[i], taken[i - j] + childDp1[j]);
                    // If this node is NOT taken, children MUST use full prices (childDp0)
                    notTaken[i] = max(notTaken[i], notTaken[i - j] + childDp0[j]);
                }
            }
        }

        vector<int> dp0(b + 1, 0), dp1(b + 1, 0);
        int cost = present[node], dCost = cost / 2;
        int profit = future[node];

        for (int i = 0; i <= b; i++) {
            // Case 1: Don't buy current node
            // The profit is whatever we got from children who couldn't use a discount
            dp0[i] = dp1[i] = notTaken[i];

            // Case 2: Buy current node at Discounted Price (Only if parent allowed it)
            if (i >= dCost) {
                dp1[i] = max(dp1[i], taken[i - dCost] + profit - dCost);
                 // Case 3: Buy current node at Full Price (Always possible if you have money)
                if (i >= cost) {
                    dp0[i] = max(dp0[i], taken[i - cost] + profit - cost);
                }
            }
        }
        return {dp1, dp0};
    }

    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        this->b = budget;
        adj.assign(n, vector<int>());
        
        for(auto& edge : hierarchy) {
            adj[edge[0] - 1].push_back(edge[1] - 1);
        }
        return dfs(0, present, future).second[budget];
    }
};