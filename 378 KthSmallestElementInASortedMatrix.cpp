/*
problem credits: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).

Solution:
    Do binary search on low and high values, and get count of it till it is equal to k
*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int low = matrix[0][0], high = matrix.back().back(), mid, count;
        while (low < high) {
            mid = (low + high) >> 1, count = getCount(matrix, mid);
            if (count < k) low = mid + 1;
            else high = mid;
        }
        return low;
    }

    int getCount(vector<vector<int>>& matrix, int ele) {
        int col = matrix.size(), i = col - 1, j = 0, count = 0;
        while (i >= 0 && j < col) {
            if (matrix[i][j] > ele) i--;
            else {
                count += i + 1;
                j++;
            }
        } 
        return count;
    }
};