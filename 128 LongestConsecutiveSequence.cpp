/*
Problem credits: https://leetcode.com/problems/longest-consecutive-sequence/

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

SOlution:
    Update ends of sequence to show how much sequence it carries
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(int i : nums) {
            if(mp[i] != 0) continue;
            mp[i - mp[i - 1]] = mp[i + mp[i+1]] = mp[i] = mp[i + 1] + mp[i -1] + 1;
            ans = max(ans, mp[i]);
        }
        return ans;
    }
};