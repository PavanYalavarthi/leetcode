/*
Problem credits: https://leetcode.com/problems/insert-interval/

You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

 * Time complexity : O(n)
 * Space complexity : O(n)

Solution:  Looking if newInterval overlaps with current, if no appending the element else updating the same with overlapped values
 */
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        for (vector<int> interval: intervals) {
            if (interval[1] < newInterval[0]) res.push_back(interval);
            else if (interval[0] > newInterval[1]) {
                res.push_back(newInterval);
                newInterval = interval;
            } else {
                newInterval[0] = min(interval[0], newInterval[0]);
                newInterval[1] = max(interval[1], newInterval[1]);
            }
        }
        res.push_back(newInterval);
        return res;
    }
};