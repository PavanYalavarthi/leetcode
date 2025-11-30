/*
 * Time complexity : O(n)
 * Space complecity : O(n)
 * Save element to index in hashmap, and check for the complement element of current element that sums up to target   
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 2) return {0, 1};
        unordered_map<int, int> indexMap;
        indexMap[nums[0]] = 0;
        for (int i = 1, other = 0; i < n; i++) {
            other = target - nums[i];
            if (indexMap.count(other) == 1) {
                return {indexMap[other], i};
            }
            indexMap[nums[i]] = i;
        }
        return {};
    }
};