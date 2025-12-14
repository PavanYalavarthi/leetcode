/*
Problem credits: https://leetcode.com/problems/copy-list-with-random-pointer/

A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. 

Solution:
    Use map to get mapping of old to new nodes.
    And copy, random and nexr pointers at creation recursively
*/
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