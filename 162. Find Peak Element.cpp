class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid; 
        while (low < high) {
            mid = (low + high) / 2;
            (nums[mid] > nums[mid + 1]) ? (high = mid) : (low = mid + 1);
        }
        return low;
    }
};