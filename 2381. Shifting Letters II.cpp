class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> v = vector(s.size() + 1, 0);
        for(auto &shift : shifts) {
            int addition = shift[2] == 0 ? -1 : 1;
            v[shift[0]] += addition;
            v[shift[1] + 1] -= addition;
        }
        partial_sum(v.begin(), v.end(), v.begin());
        for(int i = 0; i< s.size(); i++) {
            char & c = s[i];
            c = (v[i] + c - 'a')%26 + 'a';
            if(c < 'a') c += 26;
        }
        return s;
    }
};