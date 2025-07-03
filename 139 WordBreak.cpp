class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n =s.length();
        vector<bool>dp(n + 1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++) {
            for(string word: wordDict) {
                if (i >= word.length() && dp[i - word.length()] && areStringEqual(s, i, word)){
                    dp[i] = true;
                    break;
                }
            }
        } 
        return dp[n];
    }

    bool areStringEqual(const string& s, int i, const string& word) {
        // Compare the substring ending at i with the word
        return s.substr(i - word.size(), word.size()) == word;
    }
};