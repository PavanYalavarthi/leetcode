/*
 * Time complexity : O(log n)
 * Space complexity : O(1)
 * increment count for every char of s and decrement for every char of t. If they are anagrams, the value will be 0 for each;
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() -1, mid;
        while (low <= high) {
            mid = (low + high)/ 2;
            if(target == nums[mid]) return mid;
            else if (target > nums[mid]) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};