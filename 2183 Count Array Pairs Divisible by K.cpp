class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long ans = 0;
        for(int num: nums) {
            long long curGcd = __gcd(num, k);
            for(auto& [gcd, freq] : mp) {
                if (gcd * curGcd % k == 0) {
                    ans += freq;
                }
            }
            mp[curGcd]++;
        }
        return ans;
    }
};