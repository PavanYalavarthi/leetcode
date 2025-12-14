/*
problem credits: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.


Solution:
    As its sorted, use 2 pointer to get the indices.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left =0, right = numbers.size() - 1, sum;
        while (left < right) {
            sum = numbers[left] + numbers[right];
            if ( sum == target) return {left + 1, right + 1};
            else if (sum > target) right--;
            else left++;
        } 
        return {-1, -1};
    }
};