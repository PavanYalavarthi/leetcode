/*
problem credits: https://leetcode.com/problems/total-score-of-dungeon-runs/description/

You are given a positive integer hp and two positive 1-indexed integer arrays damage and requirement.

There is a dungeon with n trap rooms numbered from 1 to n. Entering room i reduces your health points by damage[i]. After that reduction, if your remaining health points are at least requirement[i], you earn 1 point for that room.

Let score(j) be the number of points you get if you start with hp health points and enter the rooms j, j + 1, ..., n in this order.

Return the integer score(1) + score(2) + ... + score(n), the sum of scores over all starting rooms.

Note: You cannot skip rooms. You can finish your journey even if your health points become non-positive.


Solution:
    We need hp - (damage[i] + .. damage[j]) >= requirement[j] => prefix[i-1] >= (requirement[i] + prefixSum[j] - hp)

    And j - i to ans;
*/

class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        int n = damage.size();
        vector<long long> prefixSum(n+1);
        prefixSum[0] = 0;
        for(int i = 0; i < n; i++) {
            prefixSum[i+1] = prefixSum[i] + damage[i];
        }
        long long ans = 0;
        for(int i = 1 ; i <= n; i++) {
            long long val = requirement[i-1] + prefixSum[i] - hp;
            int index = lower_bound(prefixSum.begin(), prefixSum.end(), val) - prefixSum.begin();
            ans += (i - min(index, i));
        }
        return ans;
    }
};