class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        mp[0] = -1;
        int presum = 0, result = 0;
        for(int i = 0; i< nums.size(); i++) {
            presum += (nums[i] == 0) ? -1 : 1;
            if(mp.find(presum) != mp.end())
                result = max(result, i - mp[presum]);
            else
                mp[presum] = i;
        }
        return result;
    }
};