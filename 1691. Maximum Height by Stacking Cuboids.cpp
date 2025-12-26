/*
problem credits: https://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/

Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose a subset of cuboids and place them on each other.

You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.

Return the maximum height of the stacked cuboids.

SOlution:
    as all dimendions should be greater than below, and height needed to be max, sort dimensions such that heigthr is last and do LIS on sorted cuboids
*/
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &cuboid: cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(), cuboids.end());
        int n = cuboids.size();
        vector<int>dp(n);
        for(int i =0; i< n; i++) {
            int ans = 0;
            for(int j =0; j< i; j++) {
                if(cuboids[i][1] >= cuboids[j][1] && cuboids[i][2] >= cuboids[j][2])
                    ans = max(ans, dp[j]);
            }
            dp[i] = ans + cuboids[i][2];
        }
        return *max_element(dp.begin(), dp.end());
    }
};