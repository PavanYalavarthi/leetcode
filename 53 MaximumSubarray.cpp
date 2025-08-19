/*
 * Time complexity : O(n)
 * Space complexity : O(1)
 * Kadane's Algo
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN, sum = 0;
        for(int num: nums) {
            sum = max(num, sum + num);
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};