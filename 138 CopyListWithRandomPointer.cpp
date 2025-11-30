/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> mp;
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        if(mp.find(head) != mp.end()) return mp[head];
        Node* node = mp[head] = new Node(head -> val);
        node -> next = copyRandomList(head -> next);
        node -> random = copyRandomList(head -> random);
        return node;
    }
};