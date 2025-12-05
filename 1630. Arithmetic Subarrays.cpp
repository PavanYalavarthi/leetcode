class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans(l.size(), true);
        for(int i=0;i<l.size();i++){
            int start = l[i], end = r[i];
            vector<int>v(nums.begin() + start , nums.begin() + end + 1);
            sort(v.begin(), v.end());
            int dif = v[1] - v[0];
            for(int j = 2;j<v.size();j++){
                if(v[j] - v[j-1] != dif){
                    ans[i] = false;
                    break;
                }
            }
        }
        return ans;
    }
};