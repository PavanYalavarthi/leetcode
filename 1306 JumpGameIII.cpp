/*
Problem credits: https://leetcode.com/problems/jump-game-iii/

Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach any index with value 0.

Notice that you can not jump outside of the array at any time.

Solution:
    Use BFS.
*/
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int>q;
        vector<bool>visited(arr.size(), false);
        q.push(start);
        while(!q.empty()) {
            int index = q.front();
            if (arr[index] == 0) return true;
            q.pop();
            if(arr[index] == -1) continue;
            if (index - arr[index] >= 0) q.push(index - arr[index]);
            if (index + arr[index] < n) q.push(index + arr[index]);
            arr[index] = -1;
        }
        return false;
    }
};