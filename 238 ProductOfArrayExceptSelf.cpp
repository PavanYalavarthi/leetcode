class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, numOfZeros = 0;
        for(int num: nums) {
            if (num == 0) numOfZeros++;
            else product *= num;
        }
        if (numOfZeros > 1) return vector<int>(nums.size(), 0);
        for (int & num: nums) {
            if (num == 0) num = product;
            else if (numOfZeros == 1) num = 0;
            else num = product / num;
        }
        return nums;
    }
};