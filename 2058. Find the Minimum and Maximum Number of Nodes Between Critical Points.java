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
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        int criticalPoint1 = -1, criticalPoint2 = -1;
        int minD = Integer.MAX_VALUE;
        ListNode current = head.next;
        for(int prev = head.val, index = 0; current != null && current.next != null;index++, prev = current.val, current = current.next ) {
            if(prev < current.val && current.val > current.next.val ||
                prev > current.val && current.val < current.next.val) {
                    if(criticalPoint1 == -1)
                        criticalPoint1 = index;
                    else
                        minD = Math.min(minD, index - criticalPoint2);
                    criticalPoint2 = index;
                    
            }
            
        }
        if(criticalPoint1 == -1 || criticalPoint2 == criticalPoint1) return new int[] { -1, -1};
        return new int[] {minD, criticalPoint2 - criticalPoint1};

    }
}