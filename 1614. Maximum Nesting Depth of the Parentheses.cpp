class Solution {
public:
    int maxDepth(string s) {
        int count = 0, ans = 0;
        for(char c: s) {
            if(c == '(') 
                ans = max(ans, ++count);
            else if(c == ')')
                count--;
        }
        return ans;
    }
};