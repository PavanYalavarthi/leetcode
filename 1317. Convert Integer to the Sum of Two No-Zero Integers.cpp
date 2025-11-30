class Solution {
public:
    bool hasNoZeros(int a) {
      while(a) {
        if (a % 10 == 0) return false;
        a /= 10;
      }
      return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i <= n /2; i++) {
          if(hasNoZeros(i) && hasNoZeros(n - i)) {
            return {i, n-i};
          }
        }
        return {-1, -1};
    }
};