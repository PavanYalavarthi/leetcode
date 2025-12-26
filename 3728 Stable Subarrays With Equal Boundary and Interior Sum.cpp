/*
Problem credits: https://leetcode.com/problems/stable-subarrays-with-equal-boundary-and-interior-sum/description/

You are given an integer array capacity.

A subarray capacity[l..r] is considered stable if:

Its length is at least 3.
The first and last elements are each equal to the sum of all elements strictly between them (i.e., capacity[l] = capacity[r] = capacity[l + 1] + capacity[l + 2] + ... + capacity[r - 1]).
Return an integer denoting the number of stable subarrays.

Solution:
    for curr element num, We need to find ele which is num and cummulative sum till that number is sum - num (as sum of between elements to be num)

    So, finding such combination.

    For curr, we increment prev as we should bt be counting len of 2. SO, we can incremnet prev after processing current
*/
class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        long long sum = 0, ans = 0;
        unordered_map<string, int> mp; 
        string prev = "#";
        for(int num: capacity) {
            ans += mp[{to_string(num) + "#" + to_string(sum - num)}];
            sum += num;
            mp[prev]++;
            prev = to_string(num) + "#" + to_string(sum); // adding prev after processing current to maintain window of 3
        }
        return ans;
    }
};