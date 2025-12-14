/*
Problem credits: https://leetcode.com/problems/course-schedule/description/

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Solution: check whether there exists a cycle
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> gr(numCourses);
        for(auto & v : prerequisites) {
            gr[v[1]].push_back(v[0]);
        }
        vector<int> visited(numCourses, false);
        for (int i = 0; i< numCourses; i++) {
            if (visited[i] == 0 && isCycle(gr, visited, i))
                return false;
        }
        return true;
    }

    bool isCycle(vector<vector<int>> & gr, vector<int> & visited, int root) {
        if (visited[root] != 0) return visited[root] == 1;
        visited[root] = 1;
        for (int neighbor: gr[root]) {
            if(isCycle(gr, visited, neighbor)) {
                return true;
            }
        }
        visited[root] = 2;
        return false;
    }
};