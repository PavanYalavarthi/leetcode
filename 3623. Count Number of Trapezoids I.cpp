/*
problem credits: https://leetcode.com/problems/count-number-of-trapezoids-i/description/

You are given a 2D integer array points, where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.

A horizontal trapezoid is a convex quadrilateral with at least one pair of horizontal sides (i.e. parallel to the x-axis). Two lines are parallel if and only if they have the same slope.

Return the number of unique horizontal trapezoids that can be formed by choosing any four distinct points from points.

Since the answer may be very large, return it modulo 109 + 7.

Solution:
    Count #points on same x. 

    Noe pick 2 points on same x i.e., freq * (feq - 1)/2

    And map them to any of the previous pairs (keep track of sum) to contribute to ans
*/
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int mod = 1e9 + 7;
        unordered_map<int, int>mp;
        for(auto point: points) {
            mp[point[1]]++;
        }
        long long sum = 0, ans = 0;
        for(auto &[_, freq]: mp) {
            long long edge =  1LL * freq * (freq - 1) / 2;
            ans = (ans + sum * edge) % mod;
            sum = (sum + edge) % mod;
        }
        return ans;
    }
};