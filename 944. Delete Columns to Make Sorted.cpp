/*
Problem credits: https://leetcode.com/problems/delete-columns-to-make-sorted/description

You are given an array of n strings strs, all of the same length.

The strings can be arranged such that there is one on each line, making a grid.

For example, strs = ["abc", "bce", "cae"] can be arranged as follows:
abc
bce
cae
You want to delete the columns that are not sorted lexicographically. In the above example (0-indexed), columns 0 ('a', 'b', 'c') and 2 ('c', 'e', 'e') are sorted, while column 1 ('b', 'c', 'a') is not, so you would delete column 1.

Return the number of columns that you will delete.


Solution: for each column, if char is lesser then previous row char, incremnt 1 and move to next col
*/

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0, m = strs.size(), n = strs[0].size();
        for(int  i= 0;i <n; i++) {
            for(int j =1; j < m; j++) {
                if (strs[j][i] < strs[j-1][i]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};