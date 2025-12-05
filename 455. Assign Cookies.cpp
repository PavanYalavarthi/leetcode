class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(),greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        int j = 0, count = 0;
        for(int i=0;i<s.size();i++,j++){
            while(j<g.size() && g[j] > s[i]) j++;
            if(j == g.size()) break;
            count++;
        }
        return count;
    }
};