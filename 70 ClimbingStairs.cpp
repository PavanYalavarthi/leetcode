/*
 * Time complexity : O(n)
 * Space complexity : O(1)
 * F(n) = F(n-1) + F(n-2) => fibonnaci series
*/

class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b =1, c = 1;
        for (int i = 2; i <= n ; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};