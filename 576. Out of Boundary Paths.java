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
        // moves--;
        // for(int i =0;i<4;i++)
            ans = (ans + solve(m,n,moves-1,row-1,col))%M;
            ans = (ans + solve(m,n,moves-1,row+1,col))%M;
            ans = (ans + solve(m,n,moves-1,row,col-1))%M;
            ans = (ans + solve(m,n,moves-1,row,col+1))%M;
        return dp[row][col][moves] = ans % M;

    }
}