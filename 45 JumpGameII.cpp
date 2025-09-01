class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        for(int i = 0, a = 0, b = 0; i < nums.size() - 1; i++, a--, b--) {
            b = max(b, nums[i]);
            if (a == 0) {
                ans++;
                a = b;
            }
        }
        return ans;
    }
};x