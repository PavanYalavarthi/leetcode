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