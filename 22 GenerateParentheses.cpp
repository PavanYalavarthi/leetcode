class Solution {
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        string s = "";
        makeParanthesis(n, n, s);
        return ans;
    }

    void makeParanthesis(int open, int close, string s) {
        if (open == 0 and close == 0) return ans.push_back(s);
        if (open > 0) makeParanthesis(open - 1, close, s + '(');
        if (open < close) makeParanthesis(open, close - 1, s + ')');
    }
};