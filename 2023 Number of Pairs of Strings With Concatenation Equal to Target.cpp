/*
problem credits: https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/description/

Given an array of digit strings nums and a digit string target, return the number of pairs of indices (i, j) (where i != j) such that the concatenation of nums[i] + nums[j] equals target.

Solution:
  Check # possibilities of string being as prefix or suffix
*/
class Solution {
 public:
  int numOfPairs(vector<string>& nums, string target) {
    const int n = target.length();
    int ans = 0;
    unordered_map<string, int> count;

    for (const string& num : nums) {
      const int k = num.length();
      if (k >= n)
        continue;
      if (target.substr(0, k) == num)
        ans += count[target.substr(k)];
      if (target.substr(n - k) == num)
        ans += count[target.substr(0, n - k)];
      ++count[num];
    }
    return ans;
  }
};
