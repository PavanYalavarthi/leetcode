class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<long long, int>mp;
        int minLen = INT_MAX;
        int n = nums.size();
        for(int i = n-1; i >= 0; i--) {
            int temp = nums[i];
            long long reverse =0LL;
            while(temp != 0) {
                reverse = reverse * 10 + temp % 10;
                temp /= 10;
            }
            if (mp.count(reverse)) {
                minLen = min(minLen, mp[reverse] - i);
            }
            mp[nums[i]] = i;
        }
        return minLen == INT_MAX ? -1 : minLen;
    }
};