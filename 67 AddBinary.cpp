/*
Problem credits: https://leetcode.com/problems/add-binary/

Given two binary strings a and b, return their sum as a binary string.

Solution: Basic binary addition, using 

*/
class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) swap(a, b);
        
        int carry = 0, j = b.size() - 1;
        string res;
        
        for (int i = a.size() - 1; i >= 0; i--) {
            carry += (a[i] - '0') + (j >= 0 ? b[j--] - '0' : 0);
            res += char((carry & 1) + '0');
            carry >>= 1;
        }
        if (carry) res += '1';
        
        reverse(res.begin(), res.end());
        return res;
    }
};
