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