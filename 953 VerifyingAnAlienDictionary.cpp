/*
Problem credits: https://leetcode.com/problems/verifying-an-alien-dictionary/

In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.

Solution:
    Store rank of each char, and do string comparision.
*/
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