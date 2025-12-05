class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
     if(s1[0] != s2[0] || s2[0]  !=  s3[0]) return -1;
     int len = min({s1.length(), s2.length(), s3.length()});
        int i = 0;
        for(;i<len;i++){
            if(s1[i] != s2[i] || s2[i] != s3[i]) break;
        }
        return s1.length() + s2.length() + s3.length() - 3 * i;
    }
};