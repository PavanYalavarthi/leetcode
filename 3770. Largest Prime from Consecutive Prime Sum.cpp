/*
problem credits: https://leetcode.com/problems/largest-prime-from-consecutive-prime-sum/description/

You are given an integer n.

Return the largest prime number less than or equal to n that can be expressed as the sum of one or more consecutive prime numbers starting from 2. If no such number exists, return 0.

Solution:
    Collect all primes and keep adding the primes and break the loop 

    And if sum exists in vector, update ans
*/

#define ll long long
class Solution {
public:
    int largestPrime(int n) {
        if (n < 2) return 0;
        if (n < 5) return 2;
        if (n < 17) return 5;
        vector<bool>isPrime(n + 1, true);
        vector<ll>prime;
        prime.push_back(2);
        prime.push_back(3);
        for(ll i = 5; i <= n ; i+= 4) {
            if (isPrime[i]) {
                prime.push_back(i);
                for(ll j = i * i; j <= n; j += 2 * i) {
                    isPrime[j] = false;
                }
            }

            i += 2;
            if (i <= n && isPrime[i]) {
                prime.push_back(i);
                for(ll j = i * i; j <= n; j += 2 * i) {
                    isPrime[j] = false;
                }
            }
        }
        ll sum = 0, ans = 0;
        for(int p: prime) {
            sum += p;
            if (sum > prime.back())
                break;
            else if (binary_search(prime.begin(), prime.end(), sum)) {
                ans = sum;
            }
        }
        return (int)ans;
    }
};