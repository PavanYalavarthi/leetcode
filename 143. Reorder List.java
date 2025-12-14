/*
problem credits: https://leetcode.com/problems/reorder-list/description/

You are given the head of a singly linked-list. The list can be represented as:

L0 -> L1 -> ... -> Ln - 1 -> Ln
Reorder the list to be on the following form:

L0 -> Ln -> L1 -> Ln - 1 -> L2 -> Ln - 2 -> ...
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Solution:
    Break the list in middle and reverse the second half, and now merge the 2 lists

*/
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public void reorderList(ListNode head) {
        ListNode slow = head, fast = head;
        while(fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        fast = slow.next;
        slow.next = null;
        ListNode prev = null, next;
        while(fast != null){
            next = fast.next;
            fast.next = prev;
            prev = fast;
            fast = next;
        }
        fast = prev;

        while( fast != null && head != null){
            prev = head.next;
            next = fast.next;
            head.next = fast;
            fast.next = prev;
            head = prev;
            fast = next;
        }

    }
}