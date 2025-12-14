/*
problem credits: https://leetcode.com/problems/contiguous-array/description/

Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

Solution:
    Add pow(-1, ele) and see if prefix sum is repeated. If yes check for longest window
*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        mp[0] = -1;
        int presum = 0, result = 0;
        for(int i = 0; i< nums.size(); i++) {
            presum += (nums[i] == 0) ? -1 : 1;
            if(mp.find(presum) != mp.end())
                result = max(result, i - mp[presum]);
            else
                mp[presum] = i;
        }
        return result;
    }
};