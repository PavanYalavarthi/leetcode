/*
Problem credits: https://leetcode.com/problems/reverse-linked-list/

Given the head of a singly linked list, reverse the list, and return the reversed list.

Solution: Keep swapping prev and next;
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
 * Time complexity : O(n)
 * Space complexity : O(1)
 * reversing the linked list
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *node = nullptr, *temp;
        while (head != nullptr) {
            temp = head -> next;
            head -> next = node;
            node = head;
            head = temp;
        }
        return node;
    }
};