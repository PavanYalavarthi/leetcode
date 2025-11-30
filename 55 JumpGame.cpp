class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_index = 0, n = nums.size();
        for(int i = 0; i<n; i++) {
            if (i > max_index) return false;
            max_index = max(max_index, i + nums[i]);
            if (max_index >= n -1) return true;
        }
        return true;
    }
};