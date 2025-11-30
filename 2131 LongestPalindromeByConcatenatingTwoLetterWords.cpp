class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        for (string& word : words) {
            mp[word]++;
        }
        int ans = 0, extraPalindrome = 0;
        for(auto &[s, freq]: mp) {
            string w(s);
            reverse(w.begin(), w.end());
            cout << s << " " << freq << endl;
            if (s == w) {
                ans += (freq / 2 * 4);
                if (freq % 2) extraPalindrome = 1;
            } else if (s < w && mp.count(w)) {
                ans += min(freq, mp[w]) * 4;
            }
        }
        return ans + extraPalindrome * 2;
    }
};