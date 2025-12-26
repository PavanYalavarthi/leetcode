/*
Problem credits: https://leetcode.com/problems/house-robber-iv/description/

There are several consecutive houses along a street, each of which has some money inside. There is also a robber, who wants to steal money from the homes, but he refuses to steal from adjacent homes.

The capability of the robber is the maximum amount of money he steals from one house of all the houses he robbed.

You are given an integer array nums representing how much money is stashed in each house. More formally, the ith house from the left has nums[i] dollars.

You are also given an integer k, representing the minimum number of houses the robber will steal from. It is always possible to steal at least k houses.

Return the minimum capability of the robber out of all the possible ways to steal at least k houses.

Solution:
    Use binary search and get how many elements are less than= mid and pick the minimum value. 
*/
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
       auto [low, high] = [](const std::vector<int>& v) {
            auto [minIt, maxIt] = std::minmax_element(v.begin(), v.end());
            return std::pair{*minIt, *maxIt};
        } (nums);
        int mid;
        while (low < high) {
            mid = (low + high) >> 1;
            if (canRob(nums, k, mid)){
                high = mid;
            } 
            else low = mid + 1;
        }
        return high;
    }

    bool canRob(vector<int>& nums, int k, int mid) {
        for(int i =0; i<nums.size(); i++) {
            if (nums[i] <= mid) {
                k--;
                if(k == 0) return true;
                i++;
            }
        }
        return false;
    }
};