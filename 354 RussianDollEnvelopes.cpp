/*
Problem credits: https://leetcode.com/problems/russian-doll-envelopes/

You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

Solution: sort things based on start and do LIS on end

*/
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int> & a, vector<int>& b) {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<int>ans;
        ans.push_back(envelopes[0][1]);
        for(int i =1; i< envelopes.size(); i++) {
            int h = envelopes[i][1];
            if (ans.back() < h) ans.push_back(h);
            else ans[lower_bound(ans.begin(), ans.end(), h) - ans.begin()] = h; 
        }
        return ans.size();
    }
};