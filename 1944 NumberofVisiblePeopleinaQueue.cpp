/*
problem credits: https://leetcode.com/problems/number-of-visible-people-in-a-queue/description/

There are n people standing in a queue, and they numbered from 0 to n - 1 in left to right order. You are given an array heights of distinct integers where heights[i] represents the height of the ith person.

A person can see another person to their right in the queue if everybody in between is shorter than both of them. More formally, the ith person can see the jth person if i < j and min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1]).

Return an array answer of length n where answer[i] is the number of people the ith person can see to their right in the queue.


Solution:
    Monotonic Stack to figure out number of elements between curr height and height > curr. Adding 1 if stack is not empty as it can take the maximum element
*/
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int>stk;
        int n = heights.size();
        stk.push(INT_MAX);
        vector<int> ans(n, 1);
        ans.back() = 0;
        for(int i = n - 2; i >= 0; i--) {
            while (stk.top() <= heights[i]) ans[i]++, stk.pop();
            stk.push(heights[i]);
        }
        return ans;
    }
};