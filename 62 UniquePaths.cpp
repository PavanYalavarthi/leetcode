/*
problem credits: https://leetcode.com/problems/unique-paths/

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

Solution: (m+n-2)c(m-1)
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m > n) swap(m, n);
        int num = m + n - 2;
        unsigned long long ans = 1;
        for(int i = 1; i < m; i++) {
            ans = ans * num / i;
            num--;
        }
        return (int)ans;
    }
};