/*
Problem credits: https://leetcode.com/problems/task-scheduler/

You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks.


Solution:
    Pick max freq ele and start it from there, Except last, everything takes n+1 space
    And we can fill the blanks with needed

    And we need to add ele with max freq at the dn and pick max of this and n
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26,0);
        for(int i = 0; i< tasks.size() ; i++)
            v[tasks[i] - 'A']++;
        int maxFreq = *max_element(v.begin(), v.end());
        int maxCount = count(v.begin(), v.end(), maxFreq);
        return max((int)tasks.size(), (maxFreq - 1) * (n + 1) + maxCount);
    }
};