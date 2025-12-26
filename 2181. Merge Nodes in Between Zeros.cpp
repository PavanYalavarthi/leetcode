/*
problem credits: https://leetcode.com/problems/merge-nodes-in-between-zeros/description/

You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.

For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

Return the head of the modified linked list.

Solution:
    Self explanatory
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        head = head->next;
        for(ListNode *start = head, *end; start != nullptr; start = start -> next) {
            int sum = 0;
            for(end = start; end -> val != 0; end = end -> next) {
                sum += end -> val;
            }
            start->val = sum;
            start->next = end->next;
        }
        return head;
    }
};