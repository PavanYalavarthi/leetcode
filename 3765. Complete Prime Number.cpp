/*
problem credits: https://leetcode.com/problems/complete-prime-number/

You are given an integer num.

A number num is called a Complete Prime Number if every prefix and every suffix of num is prime.

Return true if num is a Complete Prime Number, otherwise return false.

Note:

A prefix of a number is formed by the first k digits of the number.
A suffix of a number is formed by the last k digits of the number.
Single-digit numbers are considered Complete Prime Numbers only if they are prime.

Solution:
    get prefix and suffix of the string and if found non prime, return false;
*/
class Solution {
    bool isPrime(int n) {
        if (n == 1) return false;
        if(n <= 3) return true;
        if (n % 2 == 0 || n% 3 ==0) return false;
        for(int i = 5; i <= sqrt(n); i+=6) {
            if (((n % i) == 0) || ((n % (i + 2)) == 0))
                return false;
        }
        return true;
    }
public:
    bool completePrime(int num) {
        string s = to_string(num);
        int sum = 0;
        for(int i = 0; i < s.size(); i++) {
            sum = sum * 10 + (s[i] - '0');
            if (!isPrime(sum)) {
                return false;
            }
        }
        reverse(s.begin(), s.end());
        sum = 0;
        int pow10 = 1;
         for(int i = 0; i < s.size(); i++) {
            sum = (s[i] - '0') * pow10 +  sum;
            if (!isPrime(sum)) {
                return false;
            }
            pow10 *= 10;
        }
        return true;
    }
};