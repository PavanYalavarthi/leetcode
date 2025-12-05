class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> v(n, vector<bool>(n, true));
        for(int i = n - 2; i > -1 ;i--)
            for(int j = i + 1; j < n ;j++)
                if(s[i] != s[j] || !v[i+1][j-1])
                    v[i][j] = false;
        int count = n;
        for(int i = 0; i < n ;i++)
            for(int j = i + 1; j < n ;j++)
                if(v[i][j])
                    count++;
        return count;
    }
};