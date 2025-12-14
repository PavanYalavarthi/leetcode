/*
Problem credits: https://leetcode.com/problems/course-schedule-ii/

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

Solution: use Topological sort
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
        for (auto & prerequisite : prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
            indegree[prerequisite[0]]++;
        }   
        return topoSort(graph, indegree);
    }

    vector<int> topoSort(vector<vector<int>> & graph, vector<int> & indegree) {
        int vertices = graph.size();
        queue<int> q;
        for (int i = 0; i < vertices; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while(!q.empty()) {
            int vertex = q.front();
            q.pop();
            ans.push_back(vertex);
            for(int i: graph[vertex]) {
                if (--indegree[i] == 0)
                    q.push(i);
            }
        }
        return ans.size() == vertices ? ans : vector<int>();
    }
};