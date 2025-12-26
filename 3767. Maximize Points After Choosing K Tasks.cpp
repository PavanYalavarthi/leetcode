/*
problem credits: https://leetcode.com/problems/maximize-points-after-choosing-k-tasks/description/

You are given two integer arrays, technique1 and technique2, each of length n, where n represents the number of tasks to complete.

If the ith task is completed using technique 1, you earn technique1[i] points.
If it is completed using technique 2, you earn technique2[i] points.
You are also given an integer k, representing the minimum number of tasks that must be completed using technique 1.

You must complete at least k tasks using technique 1 (they do not need to be the first k tasks).

The remaining tasks may be completed using either technique.

Return an integer denoting the maximum total points you can earn.

Solution:
    Become greedy on technique1 - technoque2, and pick first k techique1 and rest max(tech1, tech2)
*/
class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        priority_queue<pair<long long, int>> pq;
        int n = technique1.size();
        for(int i = 0; i < n; i++) {
            pq.push({(long long)technique1[i] - technique2[i], i});
        }
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            int index = pq.top().second;
            pq.pop();
            if(i < k) {
                ans = ans + technique1[index];
            } else {
                ans = ans + max(technique1[index] , technique2[index]);
            }
        }
        return ans;
    }
};