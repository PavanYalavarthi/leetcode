/*
Problem credits: https://leetcode.com/problems/merge-in-between-linked-lists/description/

You are given two linked lists: list1 and list2 of sizes n and m respectively.

Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

The blue edges and nodes in the following figure indicate the result:


Build the result list and return its head.


Solution:
    Traverse till ath node and attach list2 and move to end of list2 and skip till b nodes and attach the next
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptrptr) {}
 *     ListNode(int x) : val(x), next(nullptrptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr = list1;
        for(int i = 1; i < a; i++) curr = curr -> next;
        ListNode* dummy = curr->next;
        curr->next = list2;
        while(curr->next) curr= curr->next;
        for(int i = a; i <= b;i++) dummy = dummy->next;
        curr->next = dummy;
        return list1;
    }
};