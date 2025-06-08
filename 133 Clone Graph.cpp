/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
* Time complexity : O(n)
 * Space complexity : O(n)
 * DFS approach
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        unordered_map<int, Node*> visited;
        helper (node, visited);
        return visited[node -> val];
    }

    void helper(Node* node, unordered_map<int, Node*>& visited) {
        Node * copy = new Node(node -> val);
        visited[node -> val] = copy;
        for(Node* child: node -> neighbors) {
            if (visited.find(child -> val) == visited.end()) {
                helper(child, visited);
            }
            copy->neighbors.push_back(visited[child->val]);
        }
    }
};