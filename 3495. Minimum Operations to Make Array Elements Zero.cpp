/*
Problem credits: https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/description/

You are given a 2D array queries, where queries[i] is of the form [l, r]. Each queries[i] defines an array of integers nums consisting of elements ranging from l to r, both inclusive.

In one operation, you can:

Select two integers a and b from the array.
Replace them with floor(a / 4) and floor(b / 4).
Your task is to determine the minimum number of operations required to reduce all elements of the array to zero for each query. Return the sum of the results for all queries.

Solution:
    Observation is for range [4^(p-1), (4^p) - 1] it takes p steps to completely make to zero.

    Now, calculate #ops to completely make each elemnt to zero. And finally as we can take 2 elements in one go. add ceil(ops/2) to ans
*/
#define ll long long
class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        ll ans = 0;
        for(auto&query: queries) {
            ll start = query[0], end = query[1];
            ll ops = 0;
            for(ll steps = 1, pow4 = 1; pow4 <= end; steps++) {
                ll l = max(start, pow4);
                pow4 <<= 2;
                ll r = min(end, pow4 - 1);
                if (r >= l) ops += (r - l + 1) * steps;
            }
            ans += (ops + 1) / 2;
        }
        return ans;
    }
};