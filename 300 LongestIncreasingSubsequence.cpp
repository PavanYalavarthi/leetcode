class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>res;
        for(int num: nums) {
            if (res.empty() || res.back() < num) {
                res.push_back(num);
            } else {
                *lower_bound(res.begin(), res.end(), num) = num;
            }
        }
        return res.size();
    }
};
