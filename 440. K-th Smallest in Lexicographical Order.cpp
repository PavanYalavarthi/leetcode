/*
Problem credits: https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/

Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

Solution:
    We check how many children we have between i and i+1, if count >= k, going to lower level

*/
class Solution {
public:
    int findKthNumber(int n, int k) {
        return solve(0, n, k);
    }

    int solve(long current, int n, int k) {
        if (k == 0) return current / 10;
        for(long i = max(1L, current); i < (current/10) * 10 + 10; i++) {
            int count = numOfChildren(i, i+1, n);
            if (count >= k) {
                return solve(i * 10, n, k - 1);
            }
            k -= count;
        }
        return -1;
    }

    int numOfChildren(long curr, long next, long n) {
        if (next > n) {
            return (curr > n) ? 0 : (n - curr + 1);
        }
        return next - curr + numOfChildren(curr * 10, next * 10, n);
    }
};