class Solution {
public:
    vector<int>dp;
    int maxJumps(vector<int>& arr, int d) {
        int mx = 1;
        dp.assign(arr.size(), -1);
        for(int  i = 0; i< arr.size(); i++) {
            mx = max(mx, helper(arr, d, i));
        }
        return mx;
    }

    int helper(vector<int>& arr, int d, int index) {
        if(dp[index] != -1) return dp[index];
        int result = 1, n = arr.size() -1;
        for(int i = index + 1; i <= min(index + d, n) && arr[index] > arr[i]; i++) {
            result = max(result, 1 + helper(arr, d, i));
        }
        for(int i = index - 1; i >= max(index - d, 0) && arr[index] > arr[i]; i--) {
            result = max(result, 1 + helper(arr, d, i));
        }
        return dp[index] = result;
    }
};