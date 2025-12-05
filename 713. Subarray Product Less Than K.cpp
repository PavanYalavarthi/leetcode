class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<2) return 0;
        int startIndex = 0, count = 0;
        for(int i = 0, product = 1; i<nums.size(); i++){
            product *= nums[i];
            while(startIndex <= i && product >= k) product /= nums[startIndex++];
            count += 1 + i - startIndex;
        }
        return count;
    }
};