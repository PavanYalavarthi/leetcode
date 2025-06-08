/*
 * Time complexity : O(m+n)
 * Space complexity : O(1)
 * Basic binary addition 
 */
class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size(), n = b.size();
        if (a.size() < b.size()) swap(a,b);
        int carry = 0, j = b.size() - 1;
        string res;
        for(int i = a.size() -1 ; i>= 0; i--) {
            carry += a[i] + (j >= 0 ? b[j--] : 0);
            res += (carry & 1) + '0';
            carry >>= 1;
        }
        if (carry) res += '1';
        reverse(begin(res), end(res));
        return res;
    }
};