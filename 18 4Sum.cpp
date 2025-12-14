/*
Problem credits: https://leetcode.com/problems/4sum/description/

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Solution:
    Similar to 15 3Sum, sort it and fix a, b and use 2 pointer for c and d. Use get unique index to avoid duplicates

    Note: use long long for sum, else int overflow occurs
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int a = 0; a < n;) {
            for(int b = a+1; b < n;) {
                int c = b+1, d = n - 1;
                while(c < d) {
                    long long sum = (long long)nums[a] + nums[b] + nums[c] + nums[d];
                    if (sum == target) {
                        ans.push_back({nums[c], nums[d], nums[b], nums[a]});
                        d--;
                        c = getNextUniqueIndex(c, nums);
                    } else if(sum < target) {
                        c++;
                    } else {
                        d--;
                    }
                }
                b = getNextUniqueIndex(b, nums);
            }
            a = getNextUniqueIndex(a, nums);
        }
        return ans;
    }

    int getNextUniqueIndex(int i, vector<int>& arr) {
        while(i < arr.size() - 1 && arr[i] == arr[i+1]) i++;
        return i + 1;
    }
};