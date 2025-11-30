class Solution {
public:
    bool isMatch(string s, string p) {
        string p1;
        char prev = 'A';
        for(int i =0 ; i< p.size(); i++) {
            if(p[i] == '*' && prev == '*') continue;
            p1.push_back(prev = p[i]);
        }
        int m = s.size(), n = p1.size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        bool ans = helper(s, p1, m - 1, n - 1, dp);
        return ans;  
    }

    bool helper(string s, string p, int i, int j, vector<vector<int>>& dp) {
        if(i == -1) return j == -1 || j == 0 && p[j] == '*';
        if(j == -1) return false;
        if(dp[i][j] != -1) return dp[i][j] == true;
        if(s[i] == p[j] || p[j] == '?') return dp[i][j] = helper(s, p, i-1, j-1, dp);
        if (p[j] == '*') return dp[i][j] = helper(s, p, i, j-1, dp) || helper(s, p, i-1, j, dp);
        return dp[i][j] = false;
    }
};