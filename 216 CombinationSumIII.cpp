class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> comb;
        makeCombinations(1, k , n, comb);
        return res;
    }

    void makeCombinations(int start, int k, int n, vector<int> & comb) {
        if (n == 0 && k == 0 ) return res.push_back(comb);
        for(int i = start; i<=9; i++) {
            if (n < k * (i + (k-1) / 2)) break;
            comb.push_back(i);
            makeCombinations(i + 1, k - 1, n - i, comb);
            comb.pop_back();
        }
    }
};