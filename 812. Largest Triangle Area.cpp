/*
Problem credits: https://leetcode.com/problems/largest-triangle-area/

Given an array of points on the X-Y plane points where points[i] = [xi, yi], return the area of the largest triangle that can be formed by any three different points. Answers within 10-5 of the actual answer will be accepted.

Solution: 
  Brute force of triangle area =  abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2;
*/
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double max_area = 0.0;
        int n = points.size();
        for(int i = 0; i < n-2; i++) {
          for(int j = i + 1; j < n - 1; j++) {
            for(int k = j + 1; k < n; k++) {
              int x1 = points[i][0], y1 = points[i][1];
              int x2 = points[j][0], y2 = points[j][1];
              int x3 = points[k][0], y3 = points[k][1];
              double area = 0.5 * abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
              max_area = max(max_area, area);
            }
          }
        }
        return max_area;
    }
};