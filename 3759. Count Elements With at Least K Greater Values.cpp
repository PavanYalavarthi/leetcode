/*
Problem credits: https://leetcode.com/problems/count-elements-with-at-least-k-greater-values/description/

You are given an integer array nums of length n and an integer k.

An element in nums is said to be qualified if there exist at least k elements in the array that are strictly greater than it.

Return an integer denoting the total number of qualified elements in nums.


Solution:
    Pushing everything to ordered set. and seeing #element > curr (which is n - (#ele <= k)) to be atleast k.
*/
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

class Solution {
   
public:
    int countElements(vector<int>& nums, int k) {
        tree < int ,  null_type ,  less_equal<int> ,  rb_tree_tag ,  tree_order_statistics_node_update > os;
        for(int num: nums) {
            os.insert(num);
        }
        int ans = 0;
        for(int num: nums) {
            ans += (nums.size() - os.order_of_key(num + 1)) >= k ;
        }
        return ans;
    }
};