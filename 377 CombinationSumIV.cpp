class Solution {
    unordered_map<int,int>dp;
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (dp.count(target) != 0) return dp[target];
        if (target == 0) return 1;
        int ans = 0;
        for (int num: nums) {
            if (target >= num)
                ans += combinationSum4(nums, target - num);
        }
        return dp[target] = ans;
    }
};