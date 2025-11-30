/*
 * Time complexity : O(n)
 * Space complexity : O(n)
 * Two pointer approach: when duplicate is seen, move startIndex to max(startIndex, duplicates previous index + 1 )
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map {{s[0], 0}};
        int startIndex = 0, ans = 0, n = s.size();
        for (int i = 1; i < n; i++) {
            if (map.find(s[i]) != map.end()) {
                ans = max(ans, i - startIndex);
                cout << ans;
                startIndex = max(startIndex, map[s[i]] + 1);
            }
            map[s[i]] = i;
        }
        return max(ans, n - startIndex);
    }
};