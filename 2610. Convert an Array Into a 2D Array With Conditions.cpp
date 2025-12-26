/*
Problem credits: https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/

You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:

The 2D array should contain only the elements of the array nums.
Each row in the 2D array contains distinct integers.
The number of rows in the 2D array should be minimal.
Return the resulting array. If there are multiple answers, return any of them.

Note that the 2D array can have a different number of elements on each row.

Solution:
    Keep freq of the digit and keep pushing it to the respective freq row
*/
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n  = nums.size();
        vector<int>freq(n + 1, 0);
        vector<vector<int>> ans;
        for(int num : nums) {
           if (freq[num] >= ans.size()) ans.push_back({});
            ans[freq[num]].push_back(num);
            freq[num]++;
        }
        return ans;
    }
};