class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, last_ele = nums.back(), mid;
        while (low < high) {
            mid = (low + high) >> 1;
            if (nums[mid] < last_ele) high = mid;
            else low = mid + 1;
        }
        return nums[low];
    }
};