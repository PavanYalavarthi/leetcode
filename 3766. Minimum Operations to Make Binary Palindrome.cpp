/*
problem credits: https://leetcode.com/problems/minimum-operations-to-make-binary-palindrome/description/

You are given an integer array nums.

For each element nums[i], you may perform the following operations any number of times (including zero):

Increase nums[i] by 1, or
Decrease nums[i] by 1.
A number is called a binary palindrome if its binary representation without leading zeros reads the same forward and backward.

Your task is to return an integer array ans, where ans[i] represents the minimum number of operations required to convert nums[i] into a binary palindrome.

Solution:
    generate palindromes < 5000 and see elemenyts near to x
*/
class Solution {
    vector<int> palindromes;
public:
    void generatePalindromes() {
        for(int i = 1; ; i++) {
            int x = i, y = i >> 1;
            while(y) {
                x = (x<<1) | y&1;
                y >>= 1;
            }
            if (x > 5000) break;
            palindromes.push_back(x);
        }

        for(int i = 1; ; i++) {
            int x = i, y = i;
            while(y) {
                x = (x<<1) | y&1;
                y >>= 1;
            }
            if (x > 5000) break;
            palindromes.push_back(x);
        }
        sort(palindromes.begin(), palindromes.end());
    }
    vector<int> minOperations(vector<int>& nums) {
        generatePalindromes();
        int n = nums.size();
        vector<int>ans(n);
        for(int i = 0; i < n; i++) {
            int x = nums[i];
            auto it = lower_bound(palindromes.begin(), palindromes.end(), x);
            int res = INT_MAX;
            if (it != palindromes.end()) {
                res = *it - x;
            }
            if (it != palindromes.begin()) {
                res = min(res, x - *prev(it));
            }
            ans[i] = res;
        }
        return ans;
    }
};