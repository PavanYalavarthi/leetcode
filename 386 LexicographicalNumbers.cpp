/*
Problem credits: https://leetcode.com/problems/lexicographical-numbers/

Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

Solution:  Running DFS on number, where if you can go deeper by mutliplying 10 we go, else increment the number
*/
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result(n);
        result[0] = 1;
        int count = 1;
        for(int i = 1; i < n; i++) {
            if (count * 10 <= n){
                count *= 10;
            } else {
                if (count >= n) count /= 10;
                count++;
                while (count % 10 == 0) count /= 10;  // Removing trailing zeros as 19 should be followed by 2, not 20
            }
            result[i] = count;
        }
        return result;
    }
};