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