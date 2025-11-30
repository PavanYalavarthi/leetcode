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