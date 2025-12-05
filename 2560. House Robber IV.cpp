class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
       auto [low, high] = [](const std::vector<int>& v) {
            auto [minIt, maxIt] = std::minmax_element(v.begin(), v.end());
            return std::pair{*minIt, *maxIt};
        } (nums);
        int mid;
        while (low < high) {
            mid = (low + high) >> 1;
            if (canRob(nums, k, mid)){
                high = mid;
                cout << mid << endl;
            } 
            else low = mid + 1;
        }
        return high;
    }

    bool canRob(vector<int>& nums, int k, int mid) {
        for(int i =0; i<nums.size(); i++) {
            if (nums[i] <= mid) {
                k--;
                if(k == 0) return true;
                i++;
            }
        }
        return false;
    }
};