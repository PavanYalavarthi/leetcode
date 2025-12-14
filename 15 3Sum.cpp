/*
Problem credits: https://leetcode.com/problems/3sum/

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Solution:
    Sort them and fix i and use find indices j and k using 2 pointer.

    Always pick i and j to be next distinct index to avoid duplicates.
*/
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