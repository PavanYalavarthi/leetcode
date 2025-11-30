class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(long long k = 1; k <= 60; k++) {
          long long x = num1 - k * num2;
          if (x < k) break;
          if (k >= __builtin_popcountll(x)) return k;
        }
        return -1;
    }
};