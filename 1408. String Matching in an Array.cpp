/*
Problem credits: https://leetcode.com/problems/string-matching-in-an-array/description/

Given an array of string words, return all strings in words that are a substring of another word. You can return the answer in any order.

Solution:
    Sort the array and check if this is part of any other string above it.
*/
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& a, string& b) {
            return a.size() < b.size();
        });
        vector<string>ans;
        int n = words.size();
        for(int i = 0; i < n-1; i++) {
            for(int j = i+1; j <n; j++) {
                if (words[j].find(words[i]) != string::npos) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};