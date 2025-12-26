/*
Problem credits: https://leetcode.com/problems/minimum-amount-of-damage-dealt-to-bob/

You are given an integer power and two integer arrays damage and health, both having length n.

Bob has n enemies, where enemy i will deal Bob damage[i] points of damage per second while they are alive (i.e. health[i] > 0).

Every second, after the enemies deal damage to Bob, he chooses one of the enemies that is still alive and deals power points of damage to them.

Determine the minimum total amount of damage points that will be dealt to Bob before all n enemies are dead.

Solution:
    We become greedy on killing enemy who does more damage/second
*/
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