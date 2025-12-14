/*
Problem credits: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Solution:
    Move to n-1th node from start and then start both first and second till first hits null.
    Now second is before nth node from end. So, delete second-<next post changing second->next
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* first = dummy;
        for(int i =0; i <= n; i++) first = first->next;
        ListNode* second = dummy;
        while(first != nullptr) {
            first = first->next;
            second = second->next;
        }
        ListNode* temp = second->next;
        second->next = temp->next;
        delete temp;
        return dummy->next;
    }
};