class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int rank[26];
        for(int i = 0; i< 26; i++) rank[order[i] - 'a'] = i;
        for(int i = 1; i < words.size(); i++) {
            if(isGreater(words[i - 1], words[i], rank))
                return false;
        }
        return true;
    }

    bool isGreater(string s, string t, int rank[]) {
        for(int i = 0; i < min(s.size(), t.size()); i++) {
            if (s[i] == t[i]) continue;
            return rank[s[i] - 'a'] > rank[t[i] - 'a']; 
        }
        return s.size() > t.size();
    }
};