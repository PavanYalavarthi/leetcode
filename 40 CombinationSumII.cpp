/*
Problem credits: https://leetcode.com/problems/combination-sum-ii/

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Solution: Same as 39 CombinationSum.cpp, but, this time we increment index
*/
class Solution {
    vector<vector<int>>res;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> comb;
        makeCombination(candidates, target, 0, comb);
        return res;
    }

    void makeCombination(vector<int>& candidates, int target, int index, vector<int>& comb) {
        if (target == 0) {
            res.push_back(comb);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if(i > index && candidates[i] == candidates[i-1]) continue;
            if(target < candidates[i]) break;
            comb.push_back(candidates[i]);
            makeCombination(candidates, target - candidates[i], i + 1, comb);
            comb.pop_back();
        }
    }
};