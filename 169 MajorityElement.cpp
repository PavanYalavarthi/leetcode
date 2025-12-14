/*
Problem description: https://leetcode.com/problems/majority-element/

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than floor(n / 2) times. You may assume that the majority element always exists in the array.

Solution: Moore's algorithm
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityElement = nums[0], count = 1;
        for (int i = 1; i< nums.size(); i++) {
            if (nums[i] == majorityElement) count++;
            else {
                count--;
                if (count == 0) {
                    count = 1;
                    majorityElement = nums[++i];
                }
            }
        }
        return majorityElement;
    }
};