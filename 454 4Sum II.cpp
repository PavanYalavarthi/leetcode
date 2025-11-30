class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mp12;
        for(int i: nums1)
            for(int j: nums2)
                mp12[i+j]++;
        int ans = 0;
        for(int k: nums3)
            for(int l: nums4)
                ans += mp12[-(k+l)];
        return ans;
    }
};