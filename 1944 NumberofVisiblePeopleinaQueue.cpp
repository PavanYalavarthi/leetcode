class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int>ans(n, 0);
        stack<int>s;
        for(int i = n - 1; i>= 0; --i) {
            while(!s.empty() && heights[i] > s.top()) ans[i]++, s.pop();
            if (!s.empty()) ans[i]++;
            s.push(heights[i]);
        }
        return ans;
    }
};