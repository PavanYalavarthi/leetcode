class Solution {
public:
    bool isPossible(vector<int>& batteries, int n, long long mid) {
        long long totalTime = 0;
        for(int i= 0; i < batteries.size(); i++) {
            totalTime += ((batteries[i] < mid) ? batteries[i]: mid);
        }
        return (totalTime >= n * mid);
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        int batterySz = batteries.size();
        long long low = 0, high = 1e14, ans = -1;
        while(low <= high) {
            long long mid = (low + high) / 2;
            if(isPossible(batteries, n , mid)) {
                ans = mid;
                low = mid +1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};