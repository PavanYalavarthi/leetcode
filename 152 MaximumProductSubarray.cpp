class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int r = -11, mn = 1, mx =1;
        for(int num : nums) {
            if (num < 0) swap(mn, mx);
            mn = min(num, mn * num);
            mx = max(num, mx * num);
            r = max(r, mx);
        }
        return r;
    }
};