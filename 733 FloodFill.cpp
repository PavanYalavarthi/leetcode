/*
Problem credits: https://leetcode.com/problems/flood-fill/

You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.


Solution: A simple DFS on the matrix
*/
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] != color)
            dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor) {
        if( sr < 0 || sc == image[0].size() || sr == image.size() || sc < 0 || image[sr][sc] != oldColor) return;
        image[sr][sc] = newColor;
        dfs(image, sr + 1, sc, oldColor, newColor);
        dfs(image, sr - 1, sc, oldColor, newColor);
        dfs(image, sr, sc + 1, oldColor, newColor);
        dfs(image, sr, sc - 1, oldColor, newColor);
    }
};