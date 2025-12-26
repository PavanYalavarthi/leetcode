/*
problem credits: https://leetcode.com/problems/minimum-deletion-cost-to-make-all-characters-equal/description/

You are given a string s of length n and an integer array cost of the same length, where cost[i] is the cost to delete the ith character of s.

You may delete any number of characters from s (possibly none), such that the resulting string is non-empty and consists of equal characters.

Return an integer denoting the minimum total deletion cost required.

Solution:
    Minimum cost is total cost - max cost of single char
*/

#define ll long long
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        vector<ll>totalCost(26, 0);
        ll total = 0, max_cost = 0;
        for(int i =0; i < cost.size(); i++) {
            max_cost = max(max_cost, totalCost[s[i] - 'a'] += cost[i]);
            total += cost[i];
        }
        return total - max_cost;
    }
};