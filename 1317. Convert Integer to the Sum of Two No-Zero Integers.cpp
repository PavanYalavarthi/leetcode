/*
problem credits: https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/description/

No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.

Given an integer n, return a list of two integers [a, b] where:

a and b are No-Zero integers.
a + b = n
The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.

Solution:
  loop from 1 to n/2 and check if there are any zeros in i and n-i
*/
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