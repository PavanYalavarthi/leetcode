class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto [a,b] = minmax_element(strs.begin(), strs.end());
        int i = 0;
        string s1 = *a, s2 = *b;
        int len = min(s1.length(), s2.length());
        while(i < len && s1[i] == s2[i] ) i++;
        return s1.substr(0,i);
    }
};