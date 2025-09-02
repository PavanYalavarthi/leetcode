class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(nums, 0, n -1, dp) >= 0;
    }

    int helper(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
        if (i == j) return nums[i];
        if(dp[i][j] != -1) return dp[i][j];
        int leftPicked = nums[i] - helper(nums, i+1, j, dp);
        int rightPicked = nums[j] - helper(nums, i, j-1, dp);
        return dp[i][j] = max(leftPicked, rightPicked);
    }
};