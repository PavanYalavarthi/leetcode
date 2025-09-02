class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        vector<vector<int>> ans;
        for(int i = 1; i< arr.size(); i++) {
            if (int diff = arr[i] - arr[i-1]; diff <= minDiff) {
                if (diff < minDiff) {
                    ans.clear();
                    minDiff = diff;
                }
                ans.push_back({arr[i-1], arr[i]});
            }
        }
        return ans;
    }
};