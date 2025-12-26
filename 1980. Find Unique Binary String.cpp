/*
Problem credits: https://leetcode.com/problems/find-unique-binary-string/description/

Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums.
If there are multiple answers, you may return any of them.

Solution:
    Flip bit of [i][i] such that none of the strings will match the result
*/
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        for(int i=0;i<nums.size();i++) {
            ans += ('1' - nums[i][i]) + '0';
        }
        return ans;
    }
};