/*
 * Time complexity : O(n^2)
 * Space complexity : O(n)
 * Two pointer approach on sorted array
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n;) {
            for (int j = i + 1, k = n - 1; j < k;) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j = getNextDistinct(j, nums);
                } else if (sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
            i = getNextDistinct(i, nums);
        }
        return ans;
    }

    int getNextDistinct(int i, const vector<int>& nums) {
        int n = nums.size(), value = nums[i];
        while (i < n && nums[i] == value) i++;
        return i;
    }
};