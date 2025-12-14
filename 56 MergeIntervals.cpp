/*
problem credits: https://leetcode.com/problems/merge-intervals/

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Solution: Sort the array based on start and keeping merging segments whose start < its end
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals.front());
        for(vector<int> & interval: intervals) {
            if (interval[0] > ans.back()[1]) ans.push_back(interval);
            else ans.back()[1] = max(ans.back()[1], interval[1]);
        }
        return ans;
    }
};