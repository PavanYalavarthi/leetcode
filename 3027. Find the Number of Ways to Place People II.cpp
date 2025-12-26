/*
Problem credits: https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/description/

You are given a 2D array points of size n x 2 representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

We define the right direction as positive x-axis (increasing x-coordinate) and the left direction as negative x-axis (decreasing x-coordinate). Similarly, we define the up direction as positive y-axis (increasing y-coordinate) and the down direction as negative y-axis (decreasing y-coordinate)

You have to place n people, including Alice and Bob, at these points such that there is exactly one person at every point. Alice wants to be alone with Bob, so Alice will build a rectangular fence with Alice's position as the upper left corner and Bob's position as the lower right corner of the fence (Note that the fence might not enclose any area, i.e. it can be a line). If any person other than Alice and Bob is either inside the fence or on the fence, Alice will be sad.

Return the number of pairs of points where you can place Alice and Bob, such that Alice does not become sad on building the fence.

Solution:
    Sort points with increasing x and decresing y.

    And see how many points you can form a rectangle

    (Same as 3025, but with bigger constraints)
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