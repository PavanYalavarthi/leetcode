class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans =0;
        for(int i = 0; i < 2 * n; i++) {
            int l = i/2, r = i/2 + (i & 1);
            while(l>= 0 && r < n && s[l] == s[r]) {
                ans++;
                l--, r++;
            }
        }
        return ans;
    }
};