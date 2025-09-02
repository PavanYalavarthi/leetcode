class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        set<int>s(nums1.begin(), nums1.end());
        long res = 0, gain = 0;
        for(int i = 0; i< nums1.size(); i++) {
            long original = abs(nums1[i] - nums2[i]);
            res += original;
            if (gain < original) {
                auto it = s.lower_bound(nums2[i]);
                if (it != s.end()) gain = max(gain, original - *it + nums2[i]);
                if (it != s.begin()) gain = max(gain, original - nums2[i] + *prev(it));
            }
        }
        return (res - gain) % 1000000007;
    }
};