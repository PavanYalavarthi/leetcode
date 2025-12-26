/*
problem credits: https://leetcode.com/problems/course-schedule-iv/description/

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.

For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.

You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.

Return a boolean array answer, where answer[j] is the answer to the jth query.



Solution: Floyd warshal algo for preprocessing
*/
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> isPrereq(numCourses, vector<bool>(numCourses, false));
        for (auto edge : prerequisites) {
            isPrereq[edge[0]][edge[1]] = true;
        }
        for (int between = 0; between < numCourses; between++) {
            for (int src = 0; src < numCourses; src++) {
                for (int sink = 0; sink < numCourses; sink++) {
                    isPrereq[src][sink] = isPrereq[src][sink] || (isPrereq[src][between] && isPrereq[between][sink]);
                }
            }
        }

        int n = queries.size();
        vector<bool> ans(n);
        for (int i =0; i < n; i++) {
            ans[i] = isPrereq[queries[i][0]][queries[i][1]];
        }
        return ans;
    }
};