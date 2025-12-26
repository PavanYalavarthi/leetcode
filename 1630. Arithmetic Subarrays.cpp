/*
Problem credits: https://leetcode.com/problems/arithmetic-subarrays/description/

A sequence of numbers is called arithmetic if it consists of at least two elements, and the difference between every two consecutive elements is the same. More formally, a sequence s is arithmetic if and only if s[i+1] - s[i] == s[1] - s[0] for all valid i.

For example, these are arithmetic sequences:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic:

1, 1, 2, 5, 7
You are given an array of n integers, nums, and two arrays of m integers each, l and r, representing the m range queries, where the ith query is the range [l[i], r[i]]. All the arrays are 0-indexed.

Return a list of boolean elements answer, where answer[i] is true if the subarray nums[l[i]], nums[l[i]+1], ... , nums[r[i]] can be rearranged to form an arithmetic sequence, and false otherwise.

Solution:
    Pick max and min from the sequence and check with given arthematic diff any element present
*/
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool>ans(n, true);
        for(int i = 0; i < n; i++) {
            int left = l[i], right = r[i];
            int mx = INT_MIN, mn = INT_MAX;
            unordered_set<int>s;
            for (int j = left; j <= right; j++) {
                mx = max(mx, nums[j]);
                mn = min(mn, nums[j]);
                s.insert(nums[j]);
            }
            int sz = right - left + 1;
            if ((mx - mn) % (sz - 1) != 0) ans[i] = false;
            else {
                int diff = (mx - mn) / (sz -1);
                int curr = mn + diff;
                while(curr < mx) {
                    if (s.count(curr) == 0) {
                        ans[i] = false;
                        break;
                    }
                    curr += diff;
                }
            }
        }
        return ans;
    }
};