class Solution {
    unordered_map<int,int> mp;
public:
    int racecar(int target) {
        if (mp.find(target) != mp.end()) return mp[target];
        int & ans = mp[target]= INT_MAX;
        int k = 32 - __builtin_clz(target);
        if ((target & (target + 1)) == 0) return ans = k;
        for ( int j = 0; j < k - 1; j++)
            ans = min(ans, k + j + 1 + racecar(target - (1 << (k - 1)) + (1 << j)));
        return ans = min(ans, k + 1 + racecar((1 << k) - 1 - target));
    }
};