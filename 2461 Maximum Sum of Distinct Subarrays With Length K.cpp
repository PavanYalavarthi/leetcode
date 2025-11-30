class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long sum =0, ans = 0;
        for(int l =0, r =0; r < nums.size(); r++) {
            int curr = nums[r];
            int lastOccurance = mp.count(curr) ? mp[curr] : -1;
            while (l <= lastOccurance || r - l + 1 > k) {
                sum -= nums[l];
                mp.erase(nums[l]);
                l++;
            } 
            sum += nums[r];
            mp[curr] = r;
            if(mp.size() == k) {
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};