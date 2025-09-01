class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++) {
            for(string word : wordDict) {
                if(int size = word.length(); i >= size && dp[i-size] && s.substr(i-size, size) == word) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};