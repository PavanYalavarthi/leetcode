class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        stack<int>s0, s1, temp;
        int n = nums.size();
        vector<int>res(n, -1);
        for (int i =0; i< n; i++) {
            while (!s1.empty() && nums[s1.top()] < nums[i]) {
                res[s1.top()] = nums[i];
                s1.pop();
            }
            while(!s0.empty() && nums[s0.top()] < nums[i]) {
                temp.push(s0.top());
                s0.pop();
            }
            while(!temp.empty()) {
                s1.push(temp.top());
                temp.pop();
            }
            s0.push(i);
        }  
        return res;
    }
};