/*
Problem credits: https://leetcode.com/problems/combination-sum/

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

Solution: Use backtracking, pick the element and not picking element.  If taregt requirfed == 0, them push combination to ans
*/
class Solution {
    vector<vector<int>>res;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> comb;
        makeCombination(candidates, target, 0, comb);
        return res;
    }

    void makeCombination(vector<int>& candidates, int target, int i, vector<int>& comb) {
        if (target == 0) res.push_back(comb);
        if(i >= candidates.size() || target < candidates[i]) return;
        comb.push_back(candidates[i]);
        makeCombination(candidates, target - candidates[i], i, comb);
        comb.pop_back();
        makeCombination(candidates, target, i + 1, comb);
    }
};