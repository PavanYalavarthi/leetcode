/*
problem credits: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/

You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once for each word in words).

Return the sum of lengths of all good strings in words.

Solution:
    check freq(chars) <= freq(words[i])
*/
class Solution {
public:
    int canFormed(string word, vector<int> v){
        for(char c : word)
            if(!(v[c-'a']--))
                return 0;
        return word.length();
    }
    int countCharacters(vector<string>& words, string chars) {
        vector<int>v(26,0);
        for(char c : chars)
            v[c - 'a']++;
        int c = 0;
        for(string word : words)
            c += canFormed(word, v);
        return c;
    }
};