/*
problem credits: https://leetcode.com/problems/next-greater-element-iv/description/

You are given a 0-indexed array of non-negative integers nums. For each integer in nums, you must find its respective second greater integer.

The second greater integer of nums[i] is nums[j] such that:

j > i
nums[j] > nums[i]
There exists exactly one index k such that nums[k] > nums[i] and i < k < j.
If there is no such nums[j], the second greater integer is considered to be -1.

Solution:
    Keep 2 stacks s1 => which have seen one greater eleemnt, s2 => seen other greater element.

    When pushing s1 to s2, inorder to preserve the order, we push to temporary array and then push to s2
*/
class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, -1);
        stack<int>s1, s2, temp;
        for(int i = 0; i < n; i++) {
            while(!s2.empty() && nums[s2.top()] < nums[i]) {
                ans[s2.top()] = nums[i];
                s2.pop();
            }
            while(!s1.empty() && nums[s1.top()] < nums[i]) {
                temp.push(s1.top());
                s1.pop();
            }
            while(!temp.empty()) {
                s2.push(temp.top());
                temp.pop();
            }
            s1.push(i);
        }
        return ans;
    }
};