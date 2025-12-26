/*
problem credits: https://leetcode.com/problems/count-vowel-strings-in-ranges/description/

You are given a 0-indexed array of strings words and a 2D array of integers queries.

Each query queries[i] = [li, ri] asks us to find the number of strings present at the indices ranging from li to ri (both inclusive) of words that start and end with a vowel.

Return an array ans of size queries.length, where ans[i] is the answer to the ith query.

Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.

Solution:
    prefix sum of number of strings with start and end as vowel.
*/
class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' ||c == 'e' ||c == 'i' ||c == 'o' ||c == 'u' ; 
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefixSum(n+1);
        prefixSum[0] = 0;
        for(int i = 0; i< n; i++) {
            prefixSum[i + 1] = prefixSum[i] +  (isVowel(words[i].front()) && isVowel(words[i].back()));
        }
        int q = queries.size();
        vector<int>ans(q);
        for(int i = 0; i < q; i++) {
            int l = queries[i][0], r = queries[i][1];
            ans[i] = prefixSum[r+1] - prefixSum[l];
        }
        return ans;
    }
};