/*
 * Time complexity : O(m)
 * Space complexity : O(1)
 * increment count for every char of s and decrement for every char of t. If they are anagrams, the value will be 0 for each;
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.size(), n = t.size();
        if (m != n) return false;
        int count[26] = {0};
        for (int i = 0; i< m; i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for(int i : count) {
            if (i != 0)
                return false;
        }
        return true;
    }
};