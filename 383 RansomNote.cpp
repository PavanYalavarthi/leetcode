/*
 * Time complexity : O(m + n)
 * Space complexity : O(1)
 * Calculating freq of each char in magazine and decrementing the same for evry char in ransomNote. If count becomes 0 before decrement returning false. else true
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int m = ransomNote.size(), n = magazine.size();
        if ( m > n) return false;
        int freq[26] = {0};
        for (char c : magazine) {
            freq[c - 'a']++;
        }
        for (char c : ransomNote) {
            int &freq_c = freq[c - 'a'];
            if (freq_c == 0) return false;
            freq_c--; 
        }
        return true;
    }
};