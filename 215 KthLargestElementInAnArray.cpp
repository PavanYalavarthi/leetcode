class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return partition(nums, 0, nums.size() - 1, k - 1);
    }
    int partition(vector<int>& nums, int left, int right, int k) {
        int pivot = nums[right], i = left;
        for (int j = left ; j < right; j++) {
            if (nums[j] > pivot) swap(nums[i++], nums[j]);
        }
        swap(nums[i], nums[right]);
        if (i == k) return pivot;
        else if (i < k) return partition(nums, i + 1, right, k);
        else return partition(nums, left, i - 1, k);
    }
};