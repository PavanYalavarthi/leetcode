class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() - 1, i = n - 1;
        while ( i >= 0 && nums[i] >= nums[i+1]) i--;
        if (i != -1) {
            int j = n;
            while (nums[i] >= nums[j]) j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};