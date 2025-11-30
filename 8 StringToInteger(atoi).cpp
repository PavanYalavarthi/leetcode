/*
    Self explanatory
*/
class Solution {
public:
    int myAtoi(string s) {
        int n = s.length(), i =0;
        while(i < n && s[i] == ' ') i++;
        if (i == n) return 0;
        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        long ans = 0;
        for( ; i < s.size() && isdigit(s[i]); i++) {
            ans = ans * 10 + (s[i] - '0');
            if (ans * sign <= INT_MIN) return INT_MIN;
            else if (ans * sign >= INT_MAX) return INT_MAX;
        }
        return (int)ans * sign; 
    }
};