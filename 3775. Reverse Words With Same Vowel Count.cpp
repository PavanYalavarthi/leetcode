/*
Problem credits: https://leetcode.com/problems/reverse-words-with-same-vowel-count/description/

You are given a string s consisting of lowercase English words, each separated by a single space.

Determine how many vowels appear in the first word. Then, reverse each following word that has the same vowel count. Leave all remaining words unchanged.

Return the resulting string.

Vowels are 'a', 'e', 'i', 'o', and 'u'.

Solution:
    Count #vowels in first string and pick all strings with equal vowel count
*/

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a'|| c == 'e' || c == 'i' || c == 'o' || c== 'u';
    }
    int vCount(string& s) {
        int cnt = 0;
        for(char c: s) {
            cnt += isVowel(c);
        }
        return cnt;
    }
    void split(string& s, vector<string>& words) {
        string temp;
        for(char c: s){
            if (c == ' ') {
                words.push_back(temp);
                temp.clear();
            } else {
                temp.push_back(c);
            }
        }
        words.push_back(temp);
    }
    string reverseWords(string s) {
        vector<string> words;
        split(s, words);
        int firstVowelsCount = vCount(words[0]);
        string ans = words[0];
        for(int i = 1; i < words.size(); i++) {
            if (vCount(words[i]) == firstVowelsCount) {
                reverse(words[i].begin(), words[i].end());
            }
            ans += " " + words[i];
        }
        return ans;
    }
};