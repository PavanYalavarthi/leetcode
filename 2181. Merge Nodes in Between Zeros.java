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
    public ListNode mergeNodes(ListNode head) {
        head = head.next;
        int sum;
        for(ListNode start = head, end; start != null; start = start.next) {
            sum = 0;
            for( end = start; end.val != 0 ; end = end.next) sum += end.val;
            start.val = sum;
            start.next = end.next;
        }
        return head;
    }
}