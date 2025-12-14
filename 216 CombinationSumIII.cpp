/*
Problem credits: https://leetcode.com/problems/combination-sum-iii/

Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.



Solution: Self explanatory
*/
class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> comb;
        makeCombinations(k, n, comb);
        return ans;
    }

    void makeCombinations(int k, int n, vector<int> &comb) {
        if (n == 0 && k == 0) ans.push_back(comb);
        for(int i = comb.empty() ? 1 : comb.back() + 1; i <= 9; i++) {
            if (n < k * (i + (k - 1) / 2 )) break;
            comb.push_back(i);
            makeCombinations(k - 1, n - i, comb);
            comb.pop_back();
        }
    }
};