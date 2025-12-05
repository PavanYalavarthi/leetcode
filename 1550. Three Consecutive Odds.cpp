class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int32_t count = 0;
        for(int num : arr) {
            if (num & 1) {
                count++;
                if (count == 3) return true;
            } 
            else count = 0;
        }
        return false;
    }
};