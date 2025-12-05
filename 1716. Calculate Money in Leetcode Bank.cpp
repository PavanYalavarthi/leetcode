class Solution {
public:
    int totalMoney(int n) {
        int week = n / 7;
        int sum = week * 28 + 7 * (week * (week-1))/2;
        if( n % 7) {
            int rem = n % 7;
            sum += rem * (2 * week + rem  + 1) / 2;
        } 
        return sum;
    }
};