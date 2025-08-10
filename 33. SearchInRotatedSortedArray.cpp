class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid, mid_ele;
        while (low <= high) {
            mid = (high + low) >> 1;
            mid_ele = nums[mid];
            if (mid_ele == target) return mid;
            if (int low_ele = nums[low]; mid_ele >= low_ele) {
                if (low_ele <= target && target <= mid_ele) high = mid - 1;
                else low = mid + 1;
            }
            else if (mid_ele <= target && target <= nums[high]) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};