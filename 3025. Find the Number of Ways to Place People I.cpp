/*
Problem credits: https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/description/

You are given a 2D array points of size n x 2 representing integer coordinates of some points on a 2D plane, where points[i] = [xi, yi].

Count the number of pairs of points (A, B), where

A is on the upper left side of B, and
there are no other points in the rectangle (or line) they make (including the border), except for the points A and B.
Return the count.


Solution:
    Sort points with increasing x and decresing y.

    And see how many points you can form a rectangle
*/
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto& a, auto&b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int n = points.size(), ans = 0;

        for(int i = 0; i < n; i++) {
            int minY = INT_MIN;
            for(int j = i+1; j < n; j++) {
                if (points[j][1] > minY && points[j][1] <= points[i][1]) {
                    ans++;
                    minY = points[j][1];
                }
            }
        }
        return ans;
    }
};