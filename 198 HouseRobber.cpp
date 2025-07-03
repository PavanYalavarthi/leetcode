class Solution {
public:
    int rob(vector<int>& nums) {
        return rob(nums, 0, nums.size());
    }

    int rob(vector<int>& nums, int start, int end) {
        int prev1 = 0, prev2 =0, temp;
        for(int i = start; i< end; i++) {
            temp = prev1;
            prev1 = max(nums[i] + prev2, prev1);
            prev2 = temp;
        }
        return prev1;
    }
};