class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() -1, ans = 0;
        for(; s[i] == ' ' ; i--);
        for(; i >= 0 && s[i] != ' '; ans++,i--) ;
        return ans;
    }
};