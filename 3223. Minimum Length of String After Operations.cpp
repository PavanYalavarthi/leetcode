class Solution {
public:
    int minimumLength(string s) {
        vector<int>v(26,0);
        for(char c: s) v[c-'a']++;
        int sum = 0;
        for(int s : v) {
            if(s == 0) continue;
            sum += s & 1 ? 1 : 2;
        }
        return sum;
    }
};