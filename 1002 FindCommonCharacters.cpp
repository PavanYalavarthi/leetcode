/*
Problem credits: https://leetcode.com/problems/find-common-characters/description/

Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

Solution: 
    Global count maintaining count of chars, and get min count of each char
*/
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>globalCount(26, INT_MAX);
        vector<int>count(26);
        for(int i =0; i< words.size(); i++) {
            fill(count.begin(), count.end(), 0);
            for (char c: words[i]) {
                count[c - 'a']++;
            }
            for(int i =0; i< 26; i++) {
                globalCount[i] = min(globalCount[i], count[i]);
            }
        }
        vector<string>ans;
        for(int i =0; i< 26; i++) {
            for (int c =0; c < globalCount[i]; c++) {
                ans.push_back(string(1, i + 'a'));
            }  
        }
        return ans;
    }
};