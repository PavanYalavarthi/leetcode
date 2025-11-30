class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long, int> mp;
        for(auto& row: wall) {
            long long sum =0;
            for(int i: row) {
                sum += i;
                mp[sum]++;
            }
            mp[sum]--;
        }
        int mx = 0;
        for(auto& [_, freq]: mp) {
            mx = max(mx, freq);
        }
        return wall.size() - mx;
    }
};