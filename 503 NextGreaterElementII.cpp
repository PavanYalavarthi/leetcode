class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, -1);
        stack<int>s;
        for(int i = 2 * n - 1, j; i >= 0; --i) {
            j = i % n;
            while(!s.empty() && s.top() <= nums[j]) s.pop();
            if(!s.empty()) ans[j] = s.top();
            s.push(nums[j]);
        }
        return ans;
    }
};