class Solution {
public:
    int minSubarray(vector<int>& nums, int k) {
        int sum = 0, n = nums.size();
        for(int num: nums) {
            sum = (sum + num) % k;
        }
        int target = sum % k;
        if (target == 0)    return 0;
        unordered_map<long long, int>mp;
        mp[0] = -1;
        int cur_sum = 0;
        int minLen = n; // Mandated to keep n to skip scenario where whole array is taken
        for(int i =0 ;i <n; i++) {
            cur_sum = (cur_sum + nums[i]) % k;
            int needed = (cur_sum - target + k) % k;
            if (mp.count(needed)) {
                cout << needed << " " << cur_sum << " " << i << endl;
                minLen = min(minLen, i - mp[needed]);
            }
            mp[cur_sum] = i;
        }
        return minLen == n ? -1 : minLen;
    } 
};