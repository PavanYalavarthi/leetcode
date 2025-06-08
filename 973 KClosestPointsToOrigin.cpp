/*
 * Time complexity : O(klogn)
 * Space complexity : O(n)
 * multi source bfs + Shortest path using bfs
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