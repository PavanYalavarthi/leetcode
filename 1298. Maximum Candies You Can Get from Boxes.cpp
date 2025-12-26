/*
problem credits: https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/description/

You have n boxes labeled from 0 to n - 1. You are given four arrays: status, candies, keys, and containedBoxes where:

status[i] is 1 if the ith box is open and 0 if the ith box is closed,
candies[i] is the number of candies in the ith box,
keys[i] is a list of the labels of the boxes you can open after opening the ith box.
containedBoxes[i] is a list of the boxes you found inside the ith box.
You are given an integer array initialBoxes that contains the labels of the boxes you initially have. You can take all the candies in any open box and you can use the keys in it to open new boxes and you also can use the boxes you find in it.

Return the maximum number of candies you can get following the rules above.

 Solution:
    keep a queue and insert the boxes available. When box is opened change th status to 1.
*/
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        bool isOpened = true;
        queue<int>q(initialBoxes.begin(), initialBoxes.end());
        int ans = 0;
        while (!q.empty() && isOpened) {
            isOpened = false;
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                int box = q.front();
                q.pop();
                if (status[box]) {
                    isOpened = true;
                    ans += candies[box];
                    for(int containedBox: containedBoxes[box]) {
                        q.push(containedBox);
                    }
                    for(int key: keys[box]) {
                        status[key] = 2;
                    }
                } else {
                    q.push(box);
                }
            }
        }
        return ans;
    }
};