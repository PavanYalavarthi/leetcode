/*
problem credits: https://leetcode.com/problems/make-three-strings-equal/description/

You are given three strings: s1, s2, and s3. In one operation you can choose one of these strings and delete its rightmost character. Note that you cannot completely empty a string.

Return the minimum number of operations required to make the strings equal. If it is impossible to make them equal, return -1.

Solution:
    as deletion can only happen from end, see from start how many chars are equal, and delete those indixes from total
*/
class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
     if(s1[0] != s2[0] || s2[0]  !=  s3[0]) return -1;
     int len = min({s1.length(), s2.length(), s3.length()});
        int i = 0;
        for(;i<len;i++){
            if(s1[i] != s2[i] || s2[i] != s3[i]) break;
        }
        return s1.length() + s2.length() + s3.length() - 3 * i;
    }
};