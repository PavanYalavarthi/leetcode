/*
problem credits: https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/description/

A company is organizing a meeting and has a list of n employees, waiting to be invited. They have arranged for a large circular table, capable of seating any number of employees.

The employees are numbered from 0 to n - 1. Each employee has a favorite person and they will attend the meeting only if they can sit next to their favorite person at the table. The favorite person of an employee is not themself.

Given a 0-indexed integer array favorite, where favorite[i] denotes the favorite person of the ith employee, return the maximum number of employees that can be invited to the meeting.

Solution:
    By pegion hole principle, there will always be a cycle. 
    FIrst we find the chain length outside the circle
    next we keep finding the cycle len, if it is of len 2, we pick adding to max chain len
    Or wqe keep maximum circle size.

    Finally we pcik max of both
*/
class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int>indegree(n, 0);
        for(int i: favorite) {
            indegree[i]++;
        }
        queue<int>q;
        for(int i =0; i <n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int>chain_len(n, 0);
        while(!q.empty()) {
            int n = q.front();
            q.pop();
            int next = favorite[n];
            chain_len[next] = chain_len[n] + 1;
            indegree[next]--;
             if (indegree[next] == 0)
                q.push(next);
        }

        int max_cycle = 0, total_chain_len = 0;
        for(int i = 0; i < n; i++) {
            if (indegree[i] != 0) {
                int curr = i, cycle_len = 0;
                while(indegree[curr] != 0) {
                    indegree[curr] = 0;
                    cycle_len++;
                    curr = favorite[curr];
                }

                if (cycle_len == 2) {
                    total_chain_len += 2 + chain_len[i] + chain_len[favorite[i]];
                } else {
                    max_cycle = max(max_cycle, cycle_len);
                }
            }
        }
        return max(max_cycle, total_chain_len);
    }
};