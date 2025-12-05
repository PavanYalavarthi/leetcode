class Solution {
    unordered_map<int, int> mp;
public:
    bool isMatch(string s, string p) {
        return helper(s, p, 0, 0);
    }

    bool helper(string s, string p, int i, int j) {
        if (i == s.size() && j >= p.size()) return true;
        if (j >= p.size()) return false;
        int key = i * 21 + j;
        if (mp.find(key) != mp.end()) return mp[key];
        bool match = i < s.size() && (s[i] == p[j] or p[j] == '.');
        if (p[j + 1] == '*')
            return mp[key] =helper(s,p, i, j + 2) || (match and helper(s,p, i + 1, j));
        if (match) return mp[key] =helper(s,p, i + 1, j + 1);
        return mp[key] = false;
    }
};