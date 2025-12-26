/*
problem credits: https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/

You are given an integer limit and a 2D array queries of size n x 2.

There are limit + 1 balls with distinct labels in the range [0, limit]. Initially, all balls are uncolored. For every query in queries that is of the form [x, y], you mark ball x with the color y. After each query, you need to find the number of colors among the balls.

Return an array result of length n, where result[i] denotes the number of colors after ith query.

Note that when answering a query, lack of a color will not be considered as a color.

Solution:
    keep track of color of given indesx and # balls with specific color in hashmap. 

    And update thing according to queries.
*/
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> mp, color;
        int queriesSz = queries.size();
        vector<int>ans(queriesSz);
        int distinct= 0;
        for(int i = 0; i < queriesSz; i++) {
            int x = queries[i][0], y = queries[i][1];
            if (color.count(x) != 0 && --mp[color[x]] == 0) {
                distinct--;
                mp.erase(color[x]);
            }
            color[x] = y;
            if (++mp[y] == 1) distinct++;
            ans[i] = distinct;
        }
        return ans;
    }
};