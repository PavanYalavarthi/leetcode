/*
problem credits: https://leetcode.com/problems/zero-array-transformation-i/description/

You are given an integer array nums of length n and a 2D array queries, where queries[i] = [li, ri].

For each queries[i]:

Select a subset of indices within the range [li, ri] in nums.
Decrement the values at the selected indices by 1.
A Zero Array is an array where all elements are equal to 0.

Return true if it is possible to transform nums into a Zero Array after processing all the queries sequentially, otherwise return false.


Solution:
    Use sweepline algorithm and if cummulative sum >= curr ele, that can be decresed to 0 else return false
*/
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& qs) {
        int n = nums.size();
        vector<int>v(n+1);
        for(auto i : qs){
            v[i[0]]++;
            v[i[1]+1]--;
        }
        int sum =0;
        for(int i=0;i<n;i++){
            sum +=v[i];
            if (nums[i] <= sum) nums[i] = 0;
            else return false;
        }
        return true;
    }
};