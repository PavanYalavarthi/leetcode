/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 * Time complexity : O(m + n)
 * Space complexity : O(1)
 * checking for smaller element and adding the node to current and moving further
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode();
        ListNode* curr = dummyHead;
        while(list1 != nullptr && list2 != nullptr) {
            if (list1 -> val >= list2 -> val) {
                curr -> next = list2;
                list2 = list2 ->next;
            } else {
                curr -> next = list1;
                list1 = list1 -> next;
            }
            curr = curr -> next;
        }
        if (list1 != nullptr) curr->next = list1;
        else curr->next = list2;
        return dummyHead->next;
    }
};