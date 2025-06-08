/*
 * Time complexity : O(n^2)
 * Space complexity : O(n)
 * Two pointer approach on sorted array
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>>s;
        int n = nums.size();
        for( int i = 0, sum; i < n; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if (sum > 0) k--;
                else if (sum < 0) j++;
                else s.insert({nums[i], nums[j++], nums[k--]});
            }
        }
        vector<vector<int>> res;
        for(vector<int> v: s) 
            res.push_back(v);
        return res;
    }
};