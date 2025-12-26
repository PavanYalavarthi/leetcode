/*
Problem credits: https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii/description/

There is a dungeon with n x m rooms arranged as a grid.

You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes one second for one move and two seconds for the next, alternating between the two.

Return the minimum time to reach the room (n - 1, m - 1).

Two rooms are adjacent if they share a common wall, either horizontally or vertically.

Solution:
    Same as leetcode 3321, just the timeToMove will be 1 or 2 based on its parity.
*/
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({0, 0, 0});
        vector<vector<int>>time(m, vector<int>(n, INT_MAX));
        time[0][0] = 0;
        int dir[] = {0, 1, 0, -1, 0};
        while(!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            int t = v[0], row = v[1], col = v[2];
            if (row == m-1 && col == n-1) return t;
            for(int i = 0; i < 4; i++) {
                int new_row = row + dir[i], new_col = col + dir[i+1];
                if (new_row == -1 || new_row == m || new_col == -1 || new_col == n) continue;
                int timeToMove = ((new_row + new_col) % 2 == 1) ? 1 : 2;
                int new_t = max(t, moveTime[new_row][new_col]) + timeToMove;

                if (new_t < time[new_row][new_col]) {
                    time[new_row][new_col] = new_t;
                    pq.push({new_t, new_row, new_col});
                }
            }
        }
        return -1;
    }
};