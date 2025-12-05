class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), ans = 0;
        vector<int>height(n, 0);
        for(auto &row : mat) {
            for(int i = 0; i < n; i++)
                height[i] = (row[i] == 0) ? 0 : height[i] + 1;
            stack<vector<int>> stk;
            stk.push({-1, -1, 0});
            for(int i = 0; i < n; i++) {
                int h = height[i];
                while(stk.top().at(1) >= h) stk.pop();
                vector<int> & top = stk.top();
                int j = top.at(0), prev = top.at(2);
                int cur = prev + (i - j) * h;
                stk.push({i, h, cur});
                ans += cur;
            }
        }
        return ans;
    }
};