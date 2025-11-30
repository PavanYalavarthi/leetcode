class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &cuboid: cuboids) {
            sort(cuboid.begin(), cuboid.end(), greater<int>());
        }
        sort(cuboids.begin(), cuboids.end(), greater<vector<int>>());
        int n = cuboids.size();
        vector<int>dp(n);
        for(int i =0; i< n; i++) {
            int ans = 0;
            for(int j =0; j< i; j++) {
                if(cuboids[i][1] <= cuboids[j][1] && cuboids[i][2] <= cuboids[j][2])
                    ans = max(ans, dp[j]);
            }
            dp[i] = ans + cuboids[i][0];
        }
        return *max_element(dp.begin(), dp.end());
    }
};