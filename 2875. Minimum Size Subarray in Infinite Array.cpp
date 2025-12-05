class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n = nums.size();
        vector<long>prefixSum(2 * n + 1);
        prefixSum[0] =0;
        for(int i = 1; i < prefixSum.size(); i++) {
            prefixSum[i] = prefixSum[i-1] + nums[(i-1) % n];
        }
        long sum = prefixSum.back() / 2;
        long rem = target % sum, quot = target / sum;
        int start = 0, end = 0,minLen = INT_MAX;
        while(end < prefixSum.size() && start <= end) {
            int total = prefixSum[end] -prefixSum[start];
            if (total == rem) {
                minLen = min(minLen, end - start);
                start++, end++;
            } else if (total < rem) {
                end++;
            } else {
               start++;
            }
        }
        return (minLen == INT_MAX) ? -1 : (quot * n) + minLen;
    }
};