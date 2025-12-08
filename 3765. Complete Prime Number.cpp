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