/*
Problem credits: https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/

You are given a 0-indexed array of strings garbage where garbage[i] represents the assortment of garbage at the ith house. garbage[i] consists only of the characters 'M', 'P' and 'G' representing one unit of metal, paper and glass garbage respectively. Picking up one unit of any type of garbage takes 1 minute.

You are also given a 0-indexed integer array travel where travel[i] is the number of minutes needed to go from house i to house i + 1.

There are three garbage trucks in the city, each responsible for picking up one type of garbage. Each garbage truck starts at house 0 and must visit each house in order; however, they do not need to visit every house.

Only one garbage truck may be used at any given moment. While one truck is driving or picking up garbage, the other two trucks cannot do anything.

Return the minimum number of minutes needed to pick up all the garbage.


Solution:
    Pick indices where g/p/g lasts and add prefix sum of travel to the ans
*/
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = travel.size();
        vector<int>prefixSum(n+1);
        prefixSum[0] = 0;
        partial_sum(travel.begin(), travel.end(), prefixSum.begin() + 1);
        int ans =0, g_idx = 0, p_idx = 0, m_idx = 0;
        for(int i = 0; i <= n ; i++) {
            for(char c: garbage[i]) {
                if (c == 'G') g_idx = i;
                else if (c == 'P') p_idx = i;
                else m_idx = i;
            }
            ans += garbage[i].size();
        }
        return ans + prefixSum[g_idx] + prefixSum[p_idx] + prefixSum[m_idx];
    }
};