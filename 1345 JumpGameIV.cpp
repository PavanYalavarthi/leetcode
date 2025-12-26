/*
problem credits: https://leetcode.com/problems/jump-game-iv/

Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.

SOlution:
    Keep hashmap with val to index and do bfs to find shortest distance from source to sink
*/
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return n - 1;
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i<n; i++) {
            mp[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        int step = -1;
        while(!q.empty()) {
            step++;
            for(int i = q.size(); i > 0; i--){
                int j = q.front();
                if (j == n - 1) return step;
                q.pop();
                for(int newIdx : mp[arr[j]]) {
                    if (newIdx != j) q.push(newIdx);
                }
                mp.erase(arr[j]);
                if (j + 1 < n && mp.count(arr[j+1]) != 0) q.push(j+1);
                if (j - 1 >= 0 && mp.count(arr[j-1]) != 0) q.push(j - 1);
            }
        }
        return step;
    }
};