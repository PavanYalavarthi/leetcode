/*
problem credits: https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii/description/

You are given a 2D binary array grid. You need to find 3 non-overlapping rectangles having non-zero areas with horizontal and vertical sides such that all the 1's in grid lie inside these rectangles.

Return the minimum possible sum of the area of these rectangles.

Note that the rectangles are allowed to touch.

Solution:
    Recursively hjaving horizontal and vertical cuts in the portions and finding out the solution
*/
class Solution {
    int INF = 1e7;

    // Helper to find the area of the smallest bounding box covering all 1s
    int getArea(vector<vector<int>>& grid, int up, int down, int left, int right) {
        int min_i = INT_MAX, max_i = -1;
        int min_j = INT_MAX, max_j = -1;
        bool found = false;

        for (int i = up; i <= down; i++) {
            for (int j = left; j <= right; j++) {
                if (grid[i][j] == 1) {
                    found = true;
                    min_i = min(min_i, i);
                    max_i = max(max_i, i);
                    min_j = min(min_j, j);
                    max_j = max(max_j, j);
                }
            }
        }
        // Return a large value if no 1s found to invalidate this partition
        return found ? (max_i - min_i + 1) * (max_j - min_j + 1) : INF;
    }

    int solve(vector<vector<int>>& grid, int up, int down, int left, int right, int cuts) {
        if (cuts == 0) return getArea(grid, up, down, left, right);

        int ans = INF;

        // Try all horizontal cut positions
        for (int i = up; i < down; i++) {
            ans = min({ans,
                solve(grid, up, i, left, right, cuts - 1) + getArea(grid, i + 1, down, left, right),
                getArea(grid, up, i, left, right) + solve(grid, i + 1, down, left, right, cuts - 1)
            });
        }

        // Try all vertical cut positions
        for (int j = left; j < right; j++) {
            ans = min({ans,
                solve(grid, up, down, left, j, cuts - 1) + getArea(grid, up, down, j + 1, right),
                getArea(grid, up, down, left, j) + solve(grid, up, down, j + 1, right, cuts - 1)
            });
        }
        return ans;
    }

public:
    int minimumSum(vector<vector<int>>& grid) {
        // Start with 2 cuts to create 3 rectangles
        return solve(grid, 0, (int)grid.size() - 1, 0, (int)grid[0].size() - 1, 2);
    }
};