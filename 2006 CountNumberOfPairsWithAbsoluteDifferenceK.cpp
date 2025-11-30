class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans= 0;
        for(int num:  nums) {
            ans += mp[num - k] + mp[num + k] - (k == 0);
            mp[num]++;
        }
        return ans;
    }
};