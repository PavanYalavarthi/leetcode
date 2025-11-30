class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0, n = nums.size() -1, sum; i < n - 1;) {
            for(int j = i + 1, k = n; j < k; ) {
                sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j = getNextDistinctIndex(nums, j);
                } else if (sum > 0) k--;
                else j++;
            }
            i = getNextDistinctIndex(nums, i);
        }
        return ans;
    }

    int getNextDistinctIndex(vector<int>& nums, int i) {
        int n = nums.size(), ele = nums[i];
        while(++i < n && nums[i] == ele);
        return i;
    }
};