/*
Problem credits: https://leetcode.com/problems/minimum-time-to-repair-cars/

You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * n2 minutes.

You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.

Return the minimum time taken to repair all the cars.

Note: All the mechanics can repair the cars simultaneously.

Solution: 
    No of cars in given time in monotonic function. So, applying binary search on time
*/
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    bool timeIsSuff(vector<int>& ranks, int cars, long long minGiven) {
        long long carsDone = 0;
        for (int r : ranks) {
            long long c2 = minGiven / r;
            long long c = floor(sqrt(c2));
            carsDone += c;
        }
        return carsDone >= cars;
    }
    
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1, r = 1e14;
        while (l < r) {
            long long mid = (l + r) / 2;
            if (timeIsSuff(ranks, cars, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};