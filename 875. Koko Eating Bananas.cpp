/*
Problem credits: https://leetcode.com/problems/koko-eating-bananas/description/

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

Solution:
    Completeing all bananas fro speed is a monotinic function. SO, binary search on it
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        while(low < high) {
            int mid = low + (high - low) / 2;
            int cnt = 0;
            for(int pile: piles) {
                cnt += ceil(1.0 * pile / mid);
            }
            if (cnt > h) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return high;
    }
};