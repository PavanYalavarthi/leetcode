/*
Problem credits: https://leetcode.com/problems/out-of-boundary-paths/description/

There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

Solution:
    Basic dfs with Dp, to avoid repeated calculations
*/
class Solution {
    int M = 1000000007;
    int [] move = {1, 0, -1 , 0 , 1};
    Integer [][][] dp = new Integer[51][51][51];
    public int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        return solve(m,n,maxMove,startRow, startColumn);
    }
    public int solve(int m, int n, int moves, int row, int col){
        if(row >= m || col >= n || row<0 || col<0) {
            return 1;
        }
        if(moves<=0){
            return 0;
        }
        if(dp[row][col][moves]!=null){
            return dp[row][col][moves];
        }
        int ans = 0;
        ans = (ans + solve(m,n,moves-1,row-1,col))%M;
        ans = (ans + solve(m,n,moves-1,row+1,col))%M;
        ans = (ans + solve(m,n,moves-1,row,col-1))%M;
        ans = (ans + solve(m,n,moves-1,row,col+1))%M;
        return dp[row][col][moves] = ans % M;
    }
}