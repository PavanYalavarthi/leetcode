/*
Problem credits: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/

You are given two 0-indexed integer permutations A and B of length n.

A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.

Return the prefix common array of A and B.

A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

Solution:
    we increment the freq of chars, if the freq becomes 2 that means this number is present on both arrays, so, incrementing count and assigning it back
*/
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), count = 0;
        vector<int> ans(n), freq(n+1, 0);
        for(int i = 0; i< n; i++) {
            if (++freq[A[i]] == 2) count++;
            if (++freq[B[i]] == 2) count++;
            ans[i] = count;
        }
        return ans;
    }
};