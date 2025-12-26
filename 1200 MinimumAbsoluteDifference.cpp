/*
Problem credits: https://leetcode.com/problems/minimum-absolute-difference/

Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr

Solution:
    sort the elements, Keep track of min difference and keep pushing adj. elements with min diff
*/
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        vector<vector<int>> ans;
        for(int i = 1; i< arr.size(); i++) {
            if (int diff = arr[i] - arr[i-1]; diff <= minDiff) {
                if (diff < minDiff) {
                    ans.clear();
                    minDiff = diff;
                }
                ans.push_back({arr[i-1], arr[i]});
            }
        }
        return ans;
    }
};