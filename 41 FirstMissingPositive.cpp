class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i =0; i<n; i++) {
            int x = nums[i];
            while(x > 0 && x <= n && x != i + 1 && nums[x - 1] != x) {
                swap(nums[x-1], nums[i]);
                x = nums[i];
            }
        }
        for(int i = 1; i <= n; i++) {
            if (nums[i - 1] != i) 
                return i;
        }
        return n + 1;
    }
};