class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long start = 0, end = 0, count = 0, ans = 0, mx = *max_element(nums.begin(), nums.end());
        do{
            if(nums[end] == mx) count++;
            while(count >= k) {
                if(nums[start++] == mx) count--;
                ans += nums.size() - end;
            }
        }while(++end < nums.size());
        return ans;
    }
};