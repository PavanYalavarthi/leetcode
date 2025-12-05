class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first = vector(26, -1);
        vector<int> last = vector(26, -1);
        int ans = 0;
        for(int i =0; i < s.size(); i++ ) {
            int curr = s[i] - 'a';
            if(first[curr] == -1) {
                first[curr] = i;
            }
            last[curr] = i;
        }
        for(int i = 0; i < 26; i++) {
            if(first[i] == last[i]) continue;
            unordered_set<char> between = unordered_set(s.begin()+first[i]+1, s.begin()+last[i]);
            ans += between.size();
        }
        return ans;
    }
};