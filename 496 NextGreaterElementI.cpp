class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for(int i = 0; i< nums1.size(); i++) mp[nums1[i]] = i;
        vector<int> ans(nums1.size(), -1);
        stack<int>s;
        for(int i = nums2.size() - 1; i >= 0; i--) {
            while(!s.empty() && s.top() < nums2[i]) s.pop();
            if (!s.empty() && mp.count(nums2[i]) != 0) ans[mp[nums2[i]]] = s.top();
            s.push(nums2[i]);
        }
        return ans;
    }
};