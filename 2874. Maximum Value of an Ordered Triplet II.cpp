class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long result = 0;
        int maxij = 0, maxi = 0;
        for (int num : nums) {
            result = max(result, 1LL * maxij * num);
            maxij = max(maxij, maxi - num);
            maxi = max(maxi, num);
        }
        return result;
    }
};
};