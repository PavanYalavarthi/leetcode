class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int ans = 0;
        for(int i = 0, oddCount; i < n; i++) {
            oddCount += nums[i] % 2;
            if (mp.count(oddCount - k)) {
                ans += mp[oddCount - k];
            }
            mp[oddCount]++;
        }
        return ans;
    }
};