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