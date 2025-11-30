class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int>s;
        int ans = 0;
        for(int l = 0, r = 0; r < nums.size(); r++) {
            s.insert(nums[r]);
            while (*s.rbegin() - *s.begin() > limit) {
                s.erase(s.find(nums[l++]));
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};