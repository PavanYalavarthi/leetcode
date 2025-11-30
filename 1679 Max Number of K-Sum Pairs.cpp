class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans =0;
        for(int num: nums) {
            if(mp[k - num]) {
                ans++;
                mp[k-num]--;
            } else {
                mp[num]++;
            }
        }
        return ans;
    }
};