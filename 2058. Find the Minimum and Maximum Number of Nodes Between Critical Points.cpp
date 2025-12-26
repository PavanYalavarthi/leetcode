/*
problem credits: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/

A critical point in a linked list is defined as either a local maxima or a local minima.

A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

Solution:
    Keep prev and check if curr can become critical point. find max and min accordingly
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
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstCritical = -1, lastCritical = -1;
        int minDistance = INT_MAX;
        ListNode* curr = head ->next;
        for(int prev = head->val, index = 1; curr != nullptr && curr->next != nullptr; prev = curr->val, curr = curr -> next, index++) {
            if (prev < curr->val && curr->val > curr->next->val || prev > curr->val && curr->val < curr->next->val) {
                if (firstCritical == -1) {
                    firstCritical = index;
                } else {
                    cout << index << " " << lastCritical << endl;
                    minDistance = min(minDistance, index - lastCritical);
                }
                lastCritical = index;
            }
        }
        if(lastCritical == firstCritical) return {-1, -1};
        return {minDistance, lastCritical - firstCritical};
    }
};