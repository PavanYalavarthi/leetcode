class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0, ans = 0, total_sum = 0;
        for(int num: nums) total_sum = (total_sum + num) % 2;
        return (total_sum  == 0) ? nums.size() -1 : 0;
    }
};