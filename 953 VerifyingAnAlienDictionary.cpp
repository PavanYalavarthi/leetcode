class Solution {
    unordered_map<char, int> mp;
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i =0 ; i< order.size();i++) mp[order[i]] = i;
        for(int i = 1; i < words.size(); i++) {
            if(isNotOrdered(words[i-1], words[i])) return false;
        }
        return true;
    }
    bool isNotOrdered(string s1, string s2) {
        for(int i = 0; i< min(s1.size(), s2.size()); i++) {
            if (mp[s1[i]] > mp[s2[i]]) return true;
            else if(mp[s1[i]] < mp[s2[i]]) return false;
        }
        return s1.size() > s2.size();
    }
};