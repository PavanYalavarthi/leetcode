class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        vector<pair<int, int>> vp;
        long long totalDamage = 0;
        for(int i = 0; i < n; i++) {
            totalDamage += damage[i];
            int time = health[i] / power + (health[i] % power != 0);
            vp.push_back({damage[i], time});
        }
        sort(vp.begin(), vp.end(), [](const auto &a, const auto &b) {
            const auto &[d1, t1] = a;
            const auto &[d2, t2] = b;
            return (double)d1 / t1 > (double)d2 / t2;
         });
        long long ans = 0;
        for(auto& [d, t] : vp) {
            ans += totalDamage * t;
            totalDamage -= d;
        }
        return ans;
    }
};