/*
Problem credits: https://leetcode.com/problems/maximum-number-of-subsequences-after-one-inserting/description/

You are given a string s consisting of uppercase English letters.

You are allowed to insert at most one uppercase English letter at any position (including the beginning or end) of the string.

Return the maximum number of "LCT" subsequences that can be formed in the resulting string after at most one insertion.

Solution:
    For extra L, maximu happens when inserted at start. And at the end for T

    and for c max prefix[l] * prefix[t]

*/
class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        vector<long long>prefix(n+1, 0), suffix(n+1, 0);
        for(int i = 1; i <= n; i++) {
            prefix[i] += prefix[i-1] + (s[i-1] == 'L');
        }
        for(int i = n-1; i >= 0; i--) {
            suffix[i] += suffix[i+1] + (s[i] == 'T');
        }
        long long ans = 0, bestWithC = 0, resWithL = 0, resWithT = 0, resWithC = 0;
        for(int i =0; i< n; i++) {
            if (s[i] == 'C') {
                resWithL += (prefix[i] + 1) * suffix[i];
                resWithT += prefix[i] * (suffix[i] + 1);
                resWithC += prefix[i] * suffix[i];
            } else {
                bestWithC = max(bestWithC, prefix[i] * suffix[i]);
            }
        }
        resWithC += bestWithC;
        return max({resWithL, resWithT, resWithC});
    }
};