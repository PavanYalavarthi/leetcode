/*
problem credits: https://leetcode.com/problems/max-number-of-k-sum-pairs/description/

You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.

Solution: 
    keep hash of nums and check if k - nums[i] exists if yes, decremnt count and increment ans
*/
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans =0;
        for(int num: nums) {
            if(mp[k - num]) {
                ans++;
                mp[k-num]--;
            } else {
                mp[num]++;
            }
        }
        return ans;
    }
};