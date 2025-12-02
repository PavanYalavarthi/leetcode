class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int mod = 1e9 + 7;
        unordered_map<int, int>mp;
        for(auto point: points) {
            mp[point[1]]++;
        }
        long long sum = 0, ans = 0;
        for(auto &[_, freq]: mp) {
            long long edge =  1LL * freq * (freq - 1) / 2;
            ans = (ans + sum * edge) % mod;
            sum = (sum + edge) % mod;
        }
        return ans;
    }
};