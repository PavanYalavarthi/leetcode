/*
problem credits: https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/description/

You are given an integer array nums.

A mirror pair is a pair of indices (i, j) such that:

0 <= i < j < nums.length, and
reverse(nums[i]) == nums[j], where reverse(x) denotes the integer formed by reversing the digits of x. Leading zeros are omitted after reversing, for example reverse(120) = 21.
Return the minimum absolute distance between the indices of any mirror pair. The absolute distance between indices i and j is abs(i - j).

If no mirror pair exists, return -1.

Solution:
    Find reverse of the number and check min differnce between i and mirror int index
*/
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<long long, int>mp;
        int minLen = INT_MAX;
        int n = nums.size();
        for(int i = n-1; i >= 0; i--) {
            int temp = nums[i];
            long long reverse =0LL;
            while(temp != 0) {
                reverse = reverse * 10 + temp % 10;
                temp /= 10;
            }
            if (mp.count(reverse)) {
                minLen = min(minLen, mp[reverse] - i);
            }
            mp[nums[i]] = i;
        }
        return minLen == INT_MAX ? -1 : minLen;
    }
};