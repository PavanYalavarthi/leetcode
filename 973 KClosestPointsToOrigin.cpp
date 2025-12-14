/*
Problem credits: https://leetcode.com/problems/k-closest-points-to-origin/

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., sqrt((x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

Solution: use min heap to push distance and index and pick k elements
 */
 class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long, int>> pq;
        for (int i = 0; i < points.size(); i++ ) {
            vector<int> point = points[i];
            pq.emplace(- (point[0] * point[0] + (long)point[1] * point[1]), i);
        }
        vector<vector<int>> res;
        for( int i = 0; i< k; i++) {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }
};