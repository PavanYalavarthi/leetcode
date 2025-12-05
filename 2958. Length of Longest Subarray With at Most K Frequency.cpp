class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans = 0;
        for(int start= 0, end =0; end<nums.size(); end++) {
            mp[nums[end]]++;
            while(mp[nums[end]] > k)
                mp[nums[start++]]--;
            ans = max(ans, end - start + 1); 
        }
        return ans;
    }
};