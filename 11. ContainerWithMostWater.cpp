class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() -1, ans =0, h;
        while (left < right) {
            h = height[left] < height[right] ? height[left++] : height[right--];
            ans = max(ans, h * (right - left + 1));
        }
        return ans;
    }
};