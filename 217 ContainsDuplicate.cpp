/*
 * Time complexity : O(n)
 * Space complexity : O(n)
 * Saving in set and returning true if element present in set
 */
 class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) {
            if(s.find(num) != s.end()) return true;
            s.insert(num);
        }
        return false;
    }
};