/*
Problem credits: https://leetcode.com/problems/h-index/

Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.

Solution: Sort them in decreasing fashion and if  citations < (i+1), then logic breaks. So return i
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end(), greater<int>());
        for(int i=0;i<n;i++){
            if(citations[i] < (i + 1)) 
                return i;
        }
        return n;
    }
};