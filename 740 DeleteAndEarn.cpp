/*
Problem credits: https://leetcode.com/problems/delete-and-earn/

You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
Return the maximum number of points you can earn by applying the above operation some number of times.

Solution:
    use dp[i] = max(dp[i-1], freq * num + dp[i-2]). Since it depends on last 2 states, using prev1 and prev2

    Using map as we needed to store freq and needed in stored order to access.
*/
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> mp;
        for(int i =0; i<nums.size(); i++) mp[nums[i]]++;
        int prev1 = 0, prev2 = 0, tmp;
        for(auto &[num, freq]: mp) {
            if(mp.count(num - 1) != 0)
                tmp = max(prev1, freq * num + prev2);
            else
                tmp = prev1 + freq * num;
            prev2 = prev1;
            prev1 = tmp;
        }
        return prev1;
    }
};