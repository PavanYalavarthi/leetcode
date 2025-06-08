/*
 * Time complexity : O(n)
 * Space complexity : O(1)
 * Kadane's Algo
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = -10001, sum = 0;
        for (int num : nums) {
            sum += num;
            max_sum = max(max_sum, sum);
            sum = max(sum, 0);
        }
        return max_sum;
    }
};