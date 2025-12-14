/*
problem credits: https://leetcode.com/problems/missing-number/

Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Solution: XOR of equal elements is 0, so xoring index ^ ele.
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 1; i <= nums.size(); i++){
            ans ^= i ^ nums[i-1];
        }
        return ans;
    }
};