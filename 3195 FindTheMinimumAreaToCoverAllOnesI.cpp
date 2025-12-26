/*
Problem credits: https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/description/

You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid lie inside this rectangle.

Return the minimum possible area of the rectangle.

Solution:
    Pick min and max of (1, j) for all cells with 1
*/
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int min_i = INT_MAX , max_i = INT_MIN, min_j = INT_MAX, max_j = INT_MIN;
        for (int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    min_i = min(min_i, i);
                    min_j = min(min_j, j);
                    max_i = max(max_i, i);
                    max_j = max(max_j, j);
                }
            }
        }
        return (max_i - min_i + 1) * (max_j - min_j + 1);
    }
};