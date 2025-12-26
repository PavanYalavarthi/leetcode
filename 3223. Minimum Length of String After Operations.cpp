/*
problem credits: https://leetcode.com/problems/minimum-length-of-string-after-operations/

You are given a string s.

You can perform the following process on s any number of times:

Choose an index i in the string such that there is at least one character to the left of index i that is equal to s[i], and at least one character to the right that is also equal to s[i].
Delete the closest occurrence of s[i] located to the left of i.
Delete the closest occurrence of s[i] located to the right of i.
Return the minimum length of the final string s that you can achieve.

 
SOlution:
    As if freq is odd, we can condense it 1 and 2 for even cases.

    Skip cases with freq 0.
*/
class Solution {
public:
    int minimumLength(string s) {
        vector<int>v(26,0);
        for(char c: s) v[c-'a']++;
        int sum = 0;
        for(int s : v) {
            if(s == 0) continue;
            sum += s & 1 ? 1 : 2;
        }
        return sum;
    }
};