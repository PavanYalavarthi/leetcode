class Solution {
public:
    int dp[105][105][25];
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int ans = func(houses,cost,target,0,0);
        if(ans>=1e9) return -1;
        return ans;
    }

    int func(vector<int>& houses, vector<vector<int>>& cost, int count, int i, int prev) {
        if (count < 0) return 1e9;
        if( i == houses.size()) {
            if (count == 0) return 0;
            else return 1e9;
        }
        if (dp[i][count][prev] != -1) return dp[i][count][prev];
        if (houses[i] != 0) {
            return dp[i][count][prev] = func(houses, cost, count - (prev != houses[i]), i +1, houses[i]);
        } else {
            int ans = 1e9;
            for (int k = 0; k <cost[i].size(); k++) {
                ans = min(ans, cost[i][k] + func(houses, cost, count - (k + 1 != prev), i + 1, k +1));
            }
            return dp[i][count][prev] = ans;
        }
        return 1e9;
    }
};