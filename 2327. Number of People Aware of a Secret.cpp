/*
Problem credits: https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/

On day 1, one person discovers a secret.

You are given an integer delay, which means that each person will share the secret with a new person every day, starting from delay days after discovering the secret. You are also given an integer forget, which means that each person will forget the secret forget days after discovering it. A person cannot share the secret on the same day they forgot it, or on any day afterwards.

Given an integer n, return the number of people who know the secret at the end of day n. Since the answer may be very large, return it modulo 109 + 7.

Solution:
    dp[i] -> #people who learn secret exactly on that day
    dp[i] = dp[i-forget+1] .. dp[i-delay] => to optimize this loop, we are using prefixSum
    Final ans = dp[n] - dp[n - forget]
*/
#define MOD 1000000007
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n+1), pref(n+1);
        dp[1] = 1;
        pref[0] = 0, pref[1] = 1;

        for (int i = 2; i <= n; i++) {
            int l = max(1, i - forget + 1);
            int r = i - delay;
            if (r >= l)
                dp[i] = (pref[r] - pref[l-1] + MOD) % MOD;
            pref[i] = (pref[i-1] + dp[i]) % MOD;
        }

        int l = max(0, n - forget);
        int ans = (pref[n] - pref[l] + MOD) % MOD;
        return ans;
    }
};