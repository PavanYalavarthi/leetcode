/*
problem credits: https://leetcode.com/problems/minimum-swaps-to-avoid-forbidden-values/description/

You are given two integer arrays, nums and forbidden, each of length n.

You may perform the following operation any number of times (including zero):

Choose two distinct indices i and j, and swap nums[i] with nums[j].
Return the minimum number of swaps required such that, for every index i, the value of nums[i] is not equal to forbidden[i]. If no amount of swaps can ensure that every index avoids its forbidden value, return -1.

Solution:
    Go greedy.

    If forbidden freq + freq > n, then we have no solution

    else, given we had badBonds, for best case, one swap can delete 2 bad bonds so best ans. = (badBonds + 1) /2

    But if an element is biggest freq of bad, then we need to do n swaps for sure.

    Get max of all combinations
*/

class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int n = nums.size();
        unordered_map<int, int> freqNums, freqForbidden, badFreq;
        int noOfBad = 0;
        for(int i = 0; i < n; i++) {
            freqNums[nums[i]]++;
            freqForbidden[forbidden[i]]++;
            if (nums[i] == forbidden[i]) {
                noOfBad++;
                badFreq[nums[i]]++;
            }
        }
        if (noOfBad == 0) return 0;

        for(auto&[ele, freq]: freqNums) {
            if (freqForbidden[ele] > n - freq)
                return -1;
        }
        int ans = (noOfBad + 1) / 2;
        for(auto& [_, freq]: badFreq) {
            ans = max(ans, freq);
        }
        return ans;
        
    }
};