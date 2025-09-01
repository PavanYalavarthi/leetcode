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