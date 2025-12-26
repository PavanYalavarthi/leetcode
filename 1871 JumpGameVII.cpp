/*
problem credits: https://leetcode.com/problems/jump-game-vii/

You are given a 0-indexed binary string s and two integers minJump and maxJump. In the beginning, you are standing at index 0, which is equal to '0'. You can move from index i to index j if the following conditions are fulfilled:

i + minJump <= j <= min(i + maxJump, s.length - 1), and
s[j] == '0'.
Return true if you can reach index s.length - 1 in s, or false otherwise.

Solution:
    keep doing bfs, from curr_max to i + max_jump
*/
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s.back() == '1') return false;
        int n = s.length();
        queue<int>q;
        q.push(0);
        int curr_max = 0;
        while(!q.empty()) {
            int i = q.front();
            if (i == n -1) return true;
            q.pop();
            for(int j = max(i+minJump , curr_max); j<=min(i+maxJump, n-1); j++) {
                if (s[j] == '0') q.push(j);
            }
            curr_max = min(1+maxJump+i, n);
        }
        return false;
    }
};