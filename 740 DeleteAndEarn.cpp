class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> mp;
        for(int i =0; i<nums.size(); i++) mp[nums[i]]++;
        int prev1 = 0, prev2 = 0, tmp;
        for(auto &[num, freq]: mp) {
            if(mp.count(num - 1) != 0)
                tmp = max(prev1, freq * num + prev2);
            else
                tmp = prev1 + freq * num;
            prev2 = prev1;
            prev1 = tmp;
        }
        return prev1;
    }
};