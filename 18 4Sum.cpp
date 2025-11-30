class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int a = 0; a < n;) {
            for(int b = a+1; b < n;) {
                int c = b+1, d = n - 1;
                while(c < d) {
                    long long sum = (long long)nums[a] + nums[b] + nums[c] + nums[d];
                    if (sum == target) {
                        ans.push_back({nums[c], nums[d], nums[b], nums[a]});
                        d--;
                        c = getNextUniqueIndex(c, nums);
                    } else if(sum < target) {
                        c++;
                    } else {
                        d--;
                    }
                }
                b = getNextUniqueIndex(b, nums);
            }
            a = getNextUniqueIndex(a, nums);
        }
        return ans;
    }

    int getNextUniqueIndex(int i, vector<int>& arr) {
        while(i < arr.size() - 1 && arr[i] == arr[i+1]) i++;
        return i + 1;
    }
};