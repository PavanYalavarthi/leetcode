class Solution {
public:
    long long exp(long long a, long long b) {
        long long ans = 1;
        a %= 1000000007;
        while(b > 0) {
            if(b & 1) (ans *= a) %= 1000000007;
            a = a * a % 1000000007;
            b >>= 1;
        }
        return ans % 1000000007;
    }
    int countGoodNumbers(long long n) {
        long long odd = n / 2;
        long long ans = exp(5,n - odd) * exp(4, odd);
        return ans % 1000000007;
    }
};