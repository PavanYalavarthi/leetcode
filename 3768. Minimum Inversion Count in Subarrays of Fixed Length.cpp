/*
Problem credits: https://leetcode.com/problems/minimum-inversion-count-in-subarrays-of-fixed-length/description/

You are given an integer array nums of length n and an integer k.

An inversion is a pair of indices (i, j) from nums such that i < j and nums[i] > nums[j].

The inversion count of a subarray is the number of inversions within it.

Return the minimum inversion count among all subarrays of nums with length k.


Solution:
    Using pbds, to get #elements > current eleeent and delete post the sliding window is out
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

class Solution {
public:
    long long minInversionCount(vector<int>& nums, int k) {
        tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> orderedSet; 
        long long invCnt = 0;
        int n = nums.size();
        for(int i = 0 ; i < k ; i++) {
            orderedSet.insert({-nums[i], i});
            invCnt += orderedSet.order_of_key({-nums[i], -1});
        }
        long long ans = invCnt;
        for(int i = k; i < n; i++) {
            invCnt = invCnt -  k + orderedSet.order_of_key({-nums[i-k], n});
            orderedSet.erase({-nums[i-k], i- k});
            orderedSet.insert({-nums[i], i});
            invCnt += orderedSet.order_of_key({-nums[i], -1});
            ans = min(ans, invCnt);
        }
        return ans;
    }
};