class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long freq=0;
        long long sum = 0;
        for(long long  l = 0, r = 0; r<nums.size();r++){
            sum += nums[r];
            if((r - l + 1) * nums[r] - sum > k ){
                sum -= nums[l++]; 
            }
            freq = max(freq, r - l +1);
        }
        return freq;
    }
};