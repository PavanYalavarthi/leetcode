/*
Problem credits: https://leetcode.com/problems/container-with-most-water/

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Solution:
    Sliding window with extremes as end points. Find max area and remove mininum height from the window.
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int>::iterator left = height.begin(), right = height.end() - 1, h = right;
        int ans = 0;
        while ( left != right ) {
            h = (*left < *right) ? left++ : right--;
            ans = max(ans, static_cast<int>(*h * (right - left + 1)));
        }
        return ans;
    }
};