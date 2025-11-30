class Solution {
    unordered_map<int, int> dp = {{0, 1}};
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (auto it = dp.find(target); it != dp.end()) return it->second;
        int ans = 0;
        for (int num: nums) {
            if (target >= num) 
                ans += combinationSum4(nums, target - num);
        }
        return dp[target] = ans;
    }
};