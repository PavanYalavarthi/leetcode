/*
 * Time complexity : O(n)
 * Space complexity : O(1)
 * Calculating freq and addinging 1 if there is an odd count
*/

class Solution {
public:
    int longestPalindrome(string s) {
        int freq[256] = {0};
        for (char c : s) {
            freq[c]++;
        }
        int ans = 0, odd = 0;
        for(int i=0; i< 256; i++) {
            ans += freq[i] / 2;
            odd = (freq[i] & 1) | odd;
        }
        return ans * 2 + odd;
    }
};