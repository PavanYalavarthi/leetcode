/*
Problem credits: https://leetcode.com/problems/count-almost-equal-pairs-ii/description/

Attention: In this version, the number of operations that can be performed, has been increased to twice.

You are given an array nums consisting of positive integers.

We call two integers x and y almost equal if both integers can become equal after performing the following operation at most twice:

Choose either x or y and swap any two digits within the chosen number.
Return the number of indices i and j in nums where i < j such that nums[i] and nums[j] are almost equal.

Note that it is allowed for an integer to have leading zeros after performing an operation.

Solution:
    Convert number to string and loop through all the possibilities of given string with max 2 swaps an incremnt the frequency

    And for given string add the freq to the string.
*/
class Solution {
    static const int max_sz = 7;
    unordered_map<string, int> freq;
    unordered_set<string> possibleStrings;
    string s = string(7, '0');
public:
    int countPairs(vector<int>& nums) {
        int ans = 0;
        for(int num: nums) {
            for(int i = max_sz - 1; i >= 0; i--) {
                s[i] = num % 10;
                num /= 10;
            }
            ans += freq[s];
            freq[s]++;
            possibleStrings.clear();
            possibleStrings.insert(s);
            for (int i = 0; i < max_sz; i++) {
                for(int j = i + 1; j < max_sz; j++) {
                    if (s[i] == s[j]) continue;
                    swap(s[i], s[j]);
                    if (possibleStrings.count(s) == 0) {
                        freq[s]++;
                        possibleStrings.insert(s);
                    }
                    for(int k = i; k < max_sz; k++) {
                        for(int l = k + 1; l < max_sz; l++) {
                            if (s[k] == s[l]) continue;
                            swap(s[k], s[l]);
                            if (possibleStrings.count(s) == 0) {
                                freq[s]++;
                                possibleStrings.insert(s);
                            }
                            swap(s[k], s[l]);
                        }
                    }
                    swap(s[i], s[j]);
                }
            }
        }
        return ans;
    }
};