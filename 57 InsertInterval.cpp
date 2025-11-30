/*
 * Time complexity : O(n)
 * Space complexity : O(n)
 * Looking if newInterval overlaps with current, if no appending the element else updating the same with overlapped values
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