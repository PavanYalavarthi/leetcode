/*
 * Time complexity : O(n)
 * Space complexity : O(1)
 * F(n) = F(n-1) + F(n-2) => fibonnaci series
*/

class Solution {
public:
    int climbStairs(int n) {
        if (n < 4) return n;
        int c;
        for(int i = 4, a = 2, b = 3, temp; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};