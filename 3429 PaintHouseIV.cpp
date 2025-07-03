class Solution {
    vector<vector<vector<long long>>> dp;
public:
    long long minCost(int n, vector<vector<int>>& cost) {
         dp.assign(n / 2 + 1, vector<vector<long long>>(4, vector<long long>(4, -1)));
        return func(cost, 0, 3, 3);
    }

    long long func(vector<vector<int>>& cost, int i, int prevColor, int prevOppColor) {
        int n = cost.size();
        if (i == n / 2) return 0;
        if(dp[i][prevColor][prevOppColor] != -1) return dp[i][prevColor][prevOppColor];
        long long ans = LONG_MAX;
        for(int color = 0; color < 3; color++) {
            if (color != prevColor) {
                for(int oppColor = 0; oppColor < 3; oppColor++) {
                    if (oppColor != prevOppColor && color != oppColor) {
                        ans = min(ans,  func(cost, i + 1, color, oppColor) + cost[i][color] + cost[n - i - 1][oppColor]);
                    }
                }
            }
        }
        return dp[i][prevColor][prevOppColor] = ans;
    }
};