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