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