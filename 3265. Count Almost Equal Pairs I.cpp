/*
problem credits: https://leetcode.com/problems/count-almost-equal-pairs-i/

You are given an array nums consisting of positive integers.

We call two integers x and y in this problem almost equal if both integers can become equal after performing the following operation at most once:

Choose either x or y and swap any two digits within the chosen number.
Return the number of indices i and j in nums where i < j such that nums[i] and nums[j] are almost equal.

Note that it is allowed for an integer to have leading zeros after performing an operation.

Solution:
    Pick 2 numbers from array and see differnce indices, If difference count > 2, skip else we need to swap those indices and see whether they are equal
*/
class Solution {
    bool areAlmostEqual(string s, string t) {
        int diff = 0, a = -1, b = -1;
        for(int i = 0; i<s.size(); i++) {
            if (s[i] != t[i]) {
                diff++;
                if (diff == 1) a = i;
                else if (diff == 2) b = i;
                else return false;
            }
        }
        if (diff == 2) {
            swap(s[a], s[b]);
        }
        return s == t;
    }
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size();
        vector<string>strs(n);
        int max_len = 0;
        for(int i = 0; i < n; i++) {
            strs[i] = to_string(nums[i]);
            max_len = max(max_len, (int)strs[i].size());
        }

        for(string& s: strs) {
            s = string(max_len - s.size(), '0') + s;
        }
        int count = 0;
        for(int i = 0; i< n; i++) {
            for(int j = i+1; j < n; j++) {
                count += areAlmostEqual(strs[i], strs[j]);
            }
        }
        return count;
    }
};