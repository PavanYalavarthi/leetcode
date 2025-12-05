class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        for(int num : nums) mp[num]++;
        int count = 0;
        for(auto &[key, val] : mp){
            if(val == 1) return -1;
            count += val/3;
            if(val%3) count++;
        }
        return count;
    }
};