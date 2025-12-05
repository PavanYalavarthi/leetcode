class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<vector<char>>v(numRows);
        int flag = 1;
        int idx = 0;
        for( int i=0;i<s.size();i++) {
            v[idx].push_back(s[i]);
            if(idx == 0) flag = 1;
            else if(idx == numRows - 1) flag = -1;
            idx += flag;
        }
        string ans;
        for(auto vt : v )
            for(auto c :vt)
                ans += c;
        return ans;
    }
};