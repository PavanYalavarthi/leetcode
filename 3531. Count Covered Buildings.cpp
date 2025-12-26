/*
Problem credits: https://leetcode.com/problems/count-covered-buildings/description/

You are given a positive integer n, representing an n x n city. You are also given a 2D grid buildings, where buildings[i] = [x, y] denotes a unique building located at coordinates [x, y].

A building is covered if there is at least one building in all four directions: left, right, above, and below.

Return the number of covered buildings.

Solution:
    Pick min and max of x and y accross y and x. And see number of points between min and max
*/
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, pair<int, int>> mpX, mpY;
        for(auto& building: buildings) {
            int x = building[0], y = building[1];
            if (mpY.count(x)) {
                auto& [minY, maxY] = mpY[x];
                minY = min(minY, y), maxY = max(maxY, y);
            } else {
                mpY[x] = {y, y};
            }
            if (mpX.count(y)) {
                auto& [minX, maxX] = mpX[y];
                minX = min(minX, x), maxX = max(maxX, x);
            } else {
                mpX[y] = {x, x};
            }
        }
        int ans = 0;
        for(auto& building: buildings) {
            int x = building[0], y = building[1];
            auto& [minY, maxY] = mpY[x];
            auto& [minX, maxX] = mpX[y];
            ans += (minX < x && x < maxX && minY < y && y < maxY);
        }
        return ans;
    }
};