/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 
 * Time complexity : O(n)
 * Space complexity : O(1)
 * Using 2 pointer approach to find the loop
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast) return true;
        }
        return false;;
    }
};