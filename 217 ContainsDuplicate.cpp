/*
 * Time complexity : O(n)
 * Space complexity : O(n)
 * Saving in set and returning true if element present in set
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++)
            if (!(s.insert(nums[i]).second)) 
                return true;
        return false;
    }
};