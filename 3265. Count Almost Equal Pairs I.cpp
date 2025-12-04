class Solution {
    bool areAlmostEqual(string s, string t) {
        int diff = 0, a = -1, b = -1;
        for(int i = 0; i<s.size(); i++) {
            if (s[i] != t[i]) {
                diff++;
                if (diff == 1) a = i;
                else if (diff == 2) b = i;
                else return false;
            }
        }
        if (diff == 2) {
            swap(s[a], s[b]);
        }
        return s == t;
    }
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size();
        vector<string>strs(n);
        int max_len = 0;
        for(int i = 0; i < n; i++) {
            strs[i] = to_string(nums[i]);
            max_len = max(max_len, (int)strs[i].size());
        }

        for(string& s: strs) {
            s = string(max_len - s.size(), '0') + s;
        }
        int count = 0;
        for(int i = 0; i< n; i++) {
            for(int j = i+1; j < n; j++) {
                count += areAlmostEqual(strs[i], strs[j]);
            }
        }
        return count;
    }
};