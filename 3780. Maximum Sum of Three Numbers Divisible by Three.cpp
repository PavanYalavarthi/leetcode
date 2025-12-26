/*
Problem credits: https://leetcode.com/problems/maximum-sum-of-three-numbers-divisible-by-three/description/

You are given an integer array nums.

Your task is to choose exactly three integers from nums such that their sum is divisible by three.

Return the maximum possible sum of such a triplet. If no such triplet exists, return 0.

Solution:
    Push integers to vector according to their mod value

    So, finally all 3 can be from same set or from set {0,1,2} each
*/

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int>rem[3];
        for(int num: nums) {
            rem[num%3].push_back(num);
        }
        for(int i =0; i<3;i++)
            sort(rem[i].rbegin(), rem[i].rend());
        int ans = 0;
        if (rem[0].size() >= 3) {
            ans = max(ans, rem[0][0] + rem[0][1] + rem[0][2]);
        }
        
        if (rem[1].size() >= 3) {
            ans = max(ans, rem[1][0] + rem[1][1] + rem[1][2]);
        }
        
        if (rem[2].size() >= 3) {
            ans = max(ans, rem[2][0] + rem[2][1] + rem[2][2]);
        }

        if (!rem[0].empty() && !rem[1].empty() && !rem[2].empty()) {
            ans = max(ans, rem[0][0] + rem[1][0] + rem[2][0]);
        }
        return ans;
    }
};