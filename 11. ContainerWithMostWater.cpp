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