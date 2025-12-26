/*
problem credits: https://leetcode.com/problems/replace-non-coprime-numbers-in-array/description/

You are given an array of integers nums. Perform the following steps:

Find any two adjacent numbers in nums that are non-coprime.
If no such numbers are found, stop the process.
Otherwise, delete the two numbers and replace them with their LCM (Least Common Multiple).
Repeat this process as long as you keep finding two adjacent non-coprime numbers.
Return the final modified array. It can be shown that replacing adjacent non-coprime numbers in any arbitrary order will lead to the same result.

The test cases are generated such that the values in the final array are less than or equal to 108.

Two values x and y are non-coprime if GCD(x, y) > 1 where GCD(x, y) is the Greatest Common Divisor of x and y.


Solution:
  use as stack and keep poping elements till we find gcd being != 1.
*/
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        for(int num: nums) {
          while(true) {
            int x = __gcd(res.empty() ? 1 : res.back(), num);
            if (x == 1) break;
            num *= res.back() / x;
            res.pop_back();
          }
          res.push_back(num);
        }
        return res;
    }
};