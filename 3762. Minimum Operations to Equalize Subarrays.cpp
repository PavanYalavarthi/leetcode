/*
problem credits: https://leetcode.com/problems/minimum-operations-to-equalize-subarrays/description/

You are given an integer array nums and an integer k.

In one operation, you can increase or decrease any element of nums by exactly k.

You are also given a 2D integer array queries, where each queries[i] = [li, ri].

For each query, find the minimum number of operations required to make all elements in the subarray nums[li..ri] equal. If it is impossible, the answer for that query is -1.

Return an array ans, where ans[i] is the answer for the ith query.

Solution:
    Since we needed to convert l to r, we need all element fro l to r to have same mod.

    So, we neeed track of last index whose mod k is equivaklent to curr k.;

    And as we needed to convert all elements to a fixed value k, that k is median.

    So using mos algo to find the median
*/

#define ll long long

struct MosAlgo {
    multiset<int> s1, s2;
    ll sum1 = 0, sum2 = 0;
    int k;

    MosAlgo(int k1) : k(k1) {}

    void balance() {
        while (s1.size() < s2.size()) {
            int x = *s2.begin();
            s2.erase(s2.begin()); sum2 -= x;
            s1.insert(x); sum1 += x;
        }
        while (s1.size() > s2.size() + 1) {
            auto it = prev(s1.end());
            int x = *it;
            s1.erase(it); sum1 -= x;
            s2.insert(x); sum2 += x;
        }
    }

    void add(int x) {
        if (s1.empty() || x <= *s1.rbegin()) {
            s1.insert(x); sum1 += x;
        } else {
            s2.insert(x); sum2 += x;
        }
        balance();
    }

    void remove(int x) {
        if (auto it = s1.find(x); it != s1.end()) {
            s1.erase(it); sum1 -= x;
        } else {
            auto it2 = s2.find(x);
            s2.erase(it2); sum2 -= x;
        }
        balance();
    }

    ll get() {
        ll x = *s1.rbegin(); // median
        return (x * (ll)s1.size() - sum1 + sum2 - x * (ll)s2.size()) / k;
    }
};

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        int BLK = sqrt(n) + 1;

        vector<int> last(n);
        last[0] = 0;
        for (int i = 1; i < n; i++) {
            last[i] = (nums[i] % k == nums[i-1] % k) ? last[i-1] : i;
        }

        int q = queries.size();
        vector<ll> ans(q, 0);
        vector<array<int,3>> Q;

        for (int i = 0; i < q; i++) {
            int l = queries[i][0], r = queries[i][1];
            if (last[r] > l) ans[i] = -1;
            else Q.push_back({l, r + 1, i});
        }

        sort(Q.begin(), Q.end(), [&BLK](auto& a, auto& b) {
            if (a[0] / BLK != b[0] / BLK) return a[0] < b[0];
            return a[1] < b[1];
        });

        MosAlgo mos(k);
        int L = 0, R = 0;

        for (auto &[l, r, idx] : Q) {
            while (l < L) mos.add(nums[--L]);
            while (r > R) mos.add(nums[R++]);
            while (l > L) mos.remove(nums[L++]);
            while (r < R) mos.remove(nums[--R]);
            ans[idx] = mos.get();
        }

        return ans;
    }
};
