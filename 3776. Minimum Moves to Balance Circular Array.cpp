/*
problem. credits: https://leetcode.com/problems/minimum-moves-to-balance-circular-array/description/

You are given a circular array balance of length n, where balance[i] is the net balance of person i.

In one move, a person can transfer exactly 1 unit of balance to either their left or right neighbor.

Return the minimum number of moves required so that every person has a non-negative balance. If it is impossible, return -1.

Note: You are guaranteed that at most 1 index has a negative balance initially.

Solution:
    Pick distance from the negative index and add distance * val to be tarnsfered to ans
*/

class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n = balance.size();
        int negIndex = -1;
        long long sum = 0;
        for(int i =0; i <n; i++) {
            int bal = balance[i];
            if (bal < 0) negIndex = i;
            sum += bal;
        }

        if (sum < 0) return -1;

        if (negIndex == -1) return 0;

        long long needed = -balance[negIndex], moves = 0;
        for(int dis = 1; dis < n && needed > 0; dis++) {
            int l = (negIndex - dis + n) % n, r = (negIndex + dis) % n;

            long long val = min(needed, (long long)balance[l]);
            moves += val * dis;
            needed -= val;
            balance[l] -= val;

            val = min(needed, (long long)balance[r]);
            moves += val * dis;
            needed -= val;
            balance[r] -= val;
        }
        return needed == 0 ? moves : -1;
    }
};