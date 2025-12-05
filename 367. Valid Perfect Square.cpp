class Solution {
public:
    bool isPerfectSquare(int num) {
        for(long long low = 1, high = num,mid; low<=high;){
            mid = low + (high - low) / 2;
            long long sq = mid * mid;
            if(sq == num) return true;
            else if(sq < num) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};