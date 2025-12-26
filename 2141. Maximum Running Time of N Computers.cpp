/*
problem credits: https://leetcode.com/problems/maximum-running-time-of-n-computers/description/

You have n computers. You are given the integer n and a 0-indexed integer array batteries where the ith battery can run a computer for batteries[i] minutes. You are interested in running all n computers simultaneously using the given batteries.

Initially, you can insert at most one battery into each computer. After that and at any integer time moment, you can remove a battery from a computer and insert another battery any number of times. The inserted battery can be a totally new battery or a battery from another computer. You may assume that the removing and inserting processes take no time.

Note that the batteries cannot be recharged.

Return the maximum number of minutes you can run all the n computers simultaneously.


Solution: as total time is monotonic, using binary search on it
*/
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