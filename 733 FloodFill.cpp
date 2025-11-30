/*
 * Time complexity : O(m * n)
 * Space complexity : O(1)
 * A simple DFS on the matrix
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