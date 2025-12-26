/*
problem credits: https://leetcode.com/problems/finding-3-digit-even-numbers/description/

You are given an integer array digits, where each element is a digit. The array may contain duplicates.

You need to find all the unique integers that follow the given requirements:

The integer consists of the concatenation of three elements from digits in any arbitrary order.
The integer does not have leading zeros.
The integer is even.
For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.

Return a sorted array of the unique integers.

Solution:
    store freq of digits and form digits that are eligible
*/
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> mpp(10, 0);
        for (int i = 0; i < digits.size(); i++)
            mpp[digits[i]]++;

        vector<int> res;
        for (int i = 1; i <= 9; i++) {
            if (mpp[i] == 0) continue;
            mpp[i]--;

            for (int j = 0; j <= 9; j++) {
                if (mpp[j] == 0) continue;
                mpp[j]--;
                for (int k = 0; k <= 8; k += 2) {
                    if (mpp[k] == 0) continue;
                    res.push_back(i*100 + j*10 + k);
                }
                mpp[j]++;

            }
            mpp[i]++;
        }
        return res;
    }
};