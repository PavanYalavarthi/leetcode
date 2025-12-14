/*
Problem credits: https://leetcode.com/problems/zigzag-conversion/

Solution: When series hits top boundaryi.e., i = 0, the incremnt of row is 1 and if it hits bottom then -1.
*/
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