/*
Problem credits: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

Solution:
    First store prefix sum to node in hash map. And skip all the nodes that are with equal to prefix sum

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> mp;
        ListNode *dummy = new ListNode(0,head);
        int presum = 0;
        for(ListNode * curr = dummy; curr != nullptr; curr = curr->next )
            mp[presum += curr -> val] = curr;
        presum = 0;
        for(ListNode * curr = dummy; curr != nullptr; curr = curr->next )
            curr -> next = mp[presum += curr -> val] -> next ;
        return dummy->next;
    }
};